#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c1,c2,ans=1e18;
int a[2000005];
LL sum[2000005];
int cnt[2000005];
int n;

#define MAXN 1000000
int minFactor[MAXN];
int prime[500000], primeNum;
void calPrime()
{
	for (int i = 2; i < MAXN; i++){
		if (!minFactor[i]){
			prime[primeNum++] = i;
			minFactor[i] = primeNum;
		}
		for (int j = 1; j <= minFactor[i]; j++){
			int t = i * prime[j - 1];
			if (t >= MAXN)break;
			minFactor[t] = j;
		}
	}
}

int main()
{
    calPrime();
    scanf("%d%lld%lld",&n,&c1,&c2);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    sum[0]=cnt[0]=0;
    int m=(c1+c2-1)/c2;
    for(int i=1;i<=2000000;i++)
    {
        cnt[i]=cnt[i-1];
        cnt[i]+=a[i];
        sum[i]=sum[i-1];
        sum[i]+=1ll*i*a[i];
    }
    for(int i=0;i<primeNum;i++)
    {
        int mask=prime[i];
        LL tot=0;
        for(int j=mask;j<=1000000+mask;j+=mask)
        {
            if(cnt[j-1]-cnt[j-mask]<=0)continue;
            if(m>=mask)tot+=1ll*c2*(1ll*j*(cnt[j-1]-cnt[j-mask])-(sum[j-1]-sum[j-mask]));
            else tot+=1ll*c1*(cnt[j-m]-cnt[j-mask])+1ll*c2*(1ll*j*(cnt[j-1]-cnt[j-m])-(sum[j-1]-sum[j-m]));
        }
        //if(ans>tot)printf("%d %lld\n",mask,tot);
        ans=min(ans,tot);
    }
    printf("%lld\n",ans);
    return 0;
}