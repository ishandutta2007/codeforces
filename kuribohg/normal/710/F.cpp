#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
const int MAXN=300010;
typedef long long LL;
int q[MAXN],l,r;
struct AC_Automaton
{
    vector<string> strs;
    map<int,int> ch[MAXN];
    int tot;
    int fail[MAXN];
    int val[MAXN];
    void insert(const string &str)
    {
        strs.push_back(str);
        int len=str.size(),x=0;
        for(int i=0;i<len;i++)
        {
            if(!ch[x].count(str[i]-'a')) ch[x][str[i]-'a']=++tot;
            x=ch[x][str[i]-'a'];
        }
        val[x]++;
    }
    void getFail()
    {
        for(int i=1;i<=tot;i++) fail[i]=0;
        l=1,r=0;
        for(int i=0;i<26;i++)
            if(ch[0].count(i)) q[++r]=ch[0][i];
        while(l<=r)
        {
            int x=q[l++];
            for(int i=0;i<26;i++)
            {
                if(!ch[x].count(i)) continue;
                int u=fail[x];
                while(u&&!ch[u].count(i)) u=fail[u];
                fail[ch[x][i]]=ch[u][i];
                q[++r]=ch[x][i];
            }
            val[x]+=val[fail[x]];
        }
    }
    LL count(const string &str)
    {
        LL ans=0;
        int len=str.size(),x=0;
        for(int i=0;i<len;i++)
        {
            while(x!=0&&!ch[x].count(str[i]-'a')) x=fail[x];
            if(ch[x].count(str[i]-'a')) x=ch[x][str[i]-'a'];
            ans+=val[x];
        }
        return ans;
    }
    void reset()
    {
        for(int i=0;i<=tot;i++)
        {
            ch[i].clear();
            fail[i]=0;
            val[i]=0;
        }
        tot=0;
        strs.clear();
    }
};
struct StaticToDynamic
{
    AC_Automaton ac[19];
    void add(const string &str)
    {
        int k=0;
        for(int i=0;i<19;i++)
            if(ac[i].strs.empty()) {k=i;break;}
        ac[k].insert(str);
        for(int i=0;i<k;i++)
        {
            for(int o=0;o<ac[i].strs.size();o++)
                ac[k].insert(ac[i].strs[o]);
            ac[i].reset();
        }
        ac[k].getFail();
    }
    LL count(const string &str)
    {
        LL ans=0;
        for(int i=0;i<19;i++)
            ans+=ac[i].count(str);
        return ans;
    }
}Ins,Del;
int n,op;
char s[MAXN];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%s",&op,s);
        string str(s);
        if(op==1) Ins.add(str);
        else if(op==2) Del.add(str);
        else
        {
            printf("%I64d\n",Ins.count(str)-Del.count(str));
            fflush(stdin);fflush(stdout);
        }
    }
    return 0;
}