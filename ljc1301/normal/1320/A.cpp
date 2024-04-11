#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
const int biase=500005;
ll b[maxn],ans[maxn+biase];
int n;
int main()
{
    int i;
    ll maxx=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld",&b[i]),ans[biase+i-b[i]]+=b[i];
    for(i=0;i<maxn+biase;i++)
        maxx=max(maxx,ans[i]);
    printf("%lld\n",maxx);
    return 0;
}