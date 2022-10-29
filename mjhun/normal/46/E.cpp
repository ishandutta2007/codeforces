#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1LL<<60)
using namespace std;
typedef long long ll;

ll x[1505][1505];
ll f[1505];
ll f2[1505];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)fore(j,0,m){
		ll k;
		scanf("%lld",&k);
		x[i][j+1]=x[i][j]+k;
	}
	fore(i,0,n){
		if(i%2==0){
			f2[0]=-INF;
			ll a=f[0];
			fore(j,1,m+1){
				f2[j]=a+x[i][j];
				a=max(a,f[j]);
			}
		}
		else {
			f2[m]=f2[0]=-INF;
			ll a=f[m];
			for(int j=m-1;j>0;--j){
				f2[j]=a+x[i][j];
				a=max(a,f[j]);
			}
		}
		memcpy(f,f2,sizeof(f));
	}
	ll r=-INF;
	fore(i,1,m+1)r=max(r,f[i]);
	printf("%lld\n",r);
	return 0;
}