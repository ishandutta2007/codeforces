#include<bits/stdc++.h>
using namespace std;

map<string,int> M;
int n,tot;
string s;
vector<int> son[510];
int ans;

int num(string s)
{
    int q=M[s];
    if (q==0)   M[s]=++tot,q=tot;
    return q;
}
void dfs(int t,int s)
{
    if (s>ans)  ans=s;
    for (int i=0;i<son[t].size();i++)
    dfs(son[t][i],s+1);
}
int main()
{
    tot=1;
    M["polycarp"]=1;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s>>s2;
        for (int i=0;i<s1.length();i++)
        if (s1[i]<='Z' && s1[i]>='A')   s1[i]=s1[i]-'A'+'a';
        for (int i=0;i<s2.length();i++)
        if (s2[i]<='Z' && s2[i]>='A')   s2[i]=s2[i]-'A'+'a';
        int ii=num(s1);
        int jj=num(s2);
        son[jj].push_back(ii);
        getchar();
    }
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}