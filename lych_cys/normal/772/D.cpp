#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 1000005
using namespace std;

int n,a[N],s[N][3],ans[N],pw[15],bin[N];
int main(){
	scanf("%d",&n);
	int i,j,k;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]); k=999999-a[i];
		s[k][0]++;
		s[k][1]=(s[k][1]+a[i])%mod;
		s[k][2]=(s[k][2]+(ll)a[i]*a[i])%mod;
	}
	pw[0]=bin[0]=1;
	for (i=1; i<=6; i++) pw[i]=pw[i-1]*10;
	for (i=1; i<=n; i++) bin[i]=(bin[i-1]<<1)%mod;
	for (i=1; i<=6; i++)
		for (j=0; j<1000000; j++) if (j/pw[i-1]%10)
			for (k=0; k<3; k++) s[j][k]=(s[j][k]+s[j-pw[i-1]][k])%mod;
	for (i=0; i<1000000; i++)
		if (s[i][0]){
			ans[i]=(ll)bin[s[i][0]-1]*s[i][2]%mod;
			if (s[i][0]>1)
				ans[i]=(ans[i]+(ll)bin[s[i][0]-2]*((ll)s[i][1]*s[i][1]%mod-s[i][2]+mod))%mod;
		}
	for (i=1; i<=6; i++)
		for (j=999999; j>=0; j--)
			if (j/pw[i-1]%10) ans[j]=(ans[j]-ans[j-pw[i-1]]+mod)%mod;
	ll sum=0;
	for (i=0; i<1000000; i++) sum^=(ll)ans[i]*(999999-i);
	printf("%lld\n",sum);
	return 0;
}