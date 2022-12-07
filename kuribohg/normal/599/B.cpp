#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=200010;
int n,m;
int a[MAXN],f[MAXN],c[MAXN],inv[MAXN];
vector<int> ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&f[i]),c[f[i]]++,inv[f[i]]=i;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        if(c[a[i]]==0) {puts("Impossible");return 0;}
    for(int i=1;i<=m;i++)
        if(c[a[i]]>1) {puts("Ambiguity");return 0;}
        else ans.push_back(inv[a[i]]);
    puts("Possible");
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}