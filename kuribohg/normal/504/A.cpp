#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,d[MAXN],s[MAXN],X[MAXN],Y[MAXN],tot;
int q[MAXN],l=1,r;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&d[i],&s[i]);
    for(int i=0;i<n;i++) if(d[i]==1) q[++r]=i;
    while(l<=r)
    {
        int x=q[l++];
        if(d[x]!=1) continue;
        ++tot;
        X[tot]=x,Y[tot]=s[x];
        d[s[x]]--,s[s[x]]^=x;
        if(d[s[x]]==1) q[++r]=s[x];
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++) printf("%d %d\n",X[i],Y[i]);
    return 0;
}