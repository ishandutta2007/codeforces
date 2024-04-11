#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAXN=1000010;
int n,k,p[MAXN],r[MAXN];
LL L,K,R,ans;
int a[MAXN];
vector<LL> f[MAXN],s[MAXN];
bool cmp(int i,int j)
{
    return a[i]<a[j];
}
int main()
{
    scanf("%d%I64d%d",&n,&L,&k);
    K=L/n,R=L%n;
    k=min((LL)k,K+(R!=0?1:0));
    for(int i=0;i<n;i++) scanf("%d",&a[i]),p[i]=i;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++) r[i]=i;
    for(int i=n-2;i>=0;i--)
        if(a[p[i]]==a[p[i+1]]) r[i]=r[i+1];
    for(int i=0;i<n;i++) f[i].resize(k+1),s[i].resize(k+1);
    for(int i=0;i<n;i++) f[i][1]=1;
    for(int i=0;i<n;i++) ans=(ans+f[i][1]*(K%MOD))%MOD;
    for(int i=0;i<R;i++) ans=(ans+f[i][1])%MOD;
    s[p[0]][1]=f[p[0]][1];
    for(int i=1;i<n;i++) s[p[i]][1]=(s[p[i-1]][1]+f[p[i]][1])%MOD;
    for(int o=2;o<=k;o++)
    {
        for(int i=0;i<n;i++) f[p[i]][o]=s[p[r[i]]][o-1];
        for(int i=0;i<n;i++) ans=(ans+f[i][o]*((K-o+1)%MOD))%MOD;
        for(int i=0;i<R;i++) ans=(ans+f[i][o])%MOD;
        s[p[0]][o]=f[p[0]][o];
        for(int i=1;i<n;i++) s[p[i]][o]=(s[p[i-1]][o]+f[p[i]][o])%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}