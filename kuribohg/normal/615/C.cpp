#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=5010;
int a,b,cur;
char S[MAXN],rS[MAXN],T[MAXN];
vector<pair<int,int> > ans;
int main()
{
    scanf("%s%s",S,T);
    a=strlen(S),b=strlen(T);
    for(int i=0;i<a;i++) rS[i]=S[i];
    reverse(rS,rS+a);
    while(cur!=b)
    {
        int farthest=-1,l,r;
        for(int i=0;i<a;i++)
        {
            int now=cur,k=i;
            while(now<b&&T[now]==S[k]) k++,now++;
            if(now>farthest) farthest=now,l=i+1,r=k;
        }
        for(int i=0;i<a;i++)
        {
            int now=cur,k=i;
            while(now<b&&T[now]==rS[k]) k++,now++;
            if(now>farthest) farthest=now,l=a-i,r=a-k+1;
        }
        if(farthest==cur) {puts("-1");return 0;}
        cur=farthest;
        ans.push_back(make_pair(l,r));
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}