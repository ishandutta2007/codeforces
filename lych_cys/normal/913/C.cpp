#include<bits/stdc++.h>
#define ll long long
#define N 109
using namespace std;

int n,m; ll a[N]; bool bo[N];
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for (i=0; i<n; i++){ bo[i]=1; scanf("%lld",&a[i]); }
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++) if ((a[i]<<j-i)<=a[j]) bo[j]=0;
	ll ans=1ll<<60,now=0; int tmp=0;
	for (i=31; i>=0; i--){
		tmp<<=1; if ((m>>i)&1) tmp|=1;
		if (bo[i]){
			//cerr<<i<<endl;
			ans=min(ans,now+(tmp+1)*a[i]);
			now+=tmp*a[i]; tmp=0;
		}
	}
//	cerr<<now<<endl;
	printf("%lld\n",min(ans,now));
	return 0;
}