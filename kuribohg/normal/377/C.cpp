#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000010;
const int INF=1000000000;
int n,N,a[220],f[MAXN],cnt[MAXN];
int T,type[21],who[21];
char op[10];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    scanf("%d",&T);
    N=min(n,T);
    for(int i=1;i<=T;i++)
    {
        scanf("%s%d",op,&who[i]);
        if(op[0]=='p') type[i]=1;
        else type[i]=2;
    }
    reverse(type+1,type+T+1);
    reverse(who+1,who+T+1);
    for(int i=1;i<(1<<N);i++)
    {
        cnt[i]=cnt[i>>1]+(i&1);
        if(who[cnt[i]]==1) f[i]=-INF;
        else f[i]=INF;
        for(int j=0;j<N;j++)
        {
            if(!(i&(1<<j))) continue;
            if(who[cnt[i]]==1) f[i]=max(f[i],f[i^(1<<j)]+((type[cnt[i]]==1)?a[j]:0));
            if(who[cnt[i]]==2) f[i]=min(f[i],f[i^(1<<j)]-((type[cnt[i]]==1)?a[j]:0));
        }
    }
    printf("%d\n",f[(1<<N)-1]);
    return 0;
}