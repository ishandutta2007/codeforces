#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,k,x;
int a[200005];
int q[32];
ll r;

int main(){
	scanf("%d%d%d",&n,&k,&x);
	fore(i,0,n){
		scanf("%d",a+i);
		fore(j,0,30)q[j]+=(a[i]>>j)&1;
	}
	ll m=1;
	fore(_,0,k)m*=x;
	r=0;
	fore(i,0,n){
		ll c=a[i]*m;
		fore(j,0,30)if(q[j]-((a[i]>>j)&1))c|=(1LL<<j);
		r=max(r,c);
	}
	printf("%lld\n",r);
	return 0;
}