#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll a[5005],q[5005],s[5005];int n;
ll r[10005],v[10005];

int main(){
	scanf("%d",&n);
	fore(i,0,n-1)scanf("%lld",a+i);
	s[0]=1;
	fore(i,1,n)s[i]=s[i-1]*a[i-1]%MOD;
	q[n-1]=1;
	for(int i=n-2;i>=0;--i)q[i]=(1+a[i]*q[i+1])%MOD;
	fore(i,0,n){
		fore(j,1,2*n-1){
			r[j]+=s[i]*v[j]%MOD;
			if(r[j]>=MOD)r[j]-=MOD;
		}
		ll t=a[i];
		fore(j,i+1,n){
			r[j-i]+=s[i]*t%MOD;
			if(r[j-i]>=MOD)r[j-i]-=MOD;
			t=(t*a[j])%MOD;
		}
		if(i==n-1)break;
		for(int i=2*n-2;i>0;--i)v[i]=v[i-1];
		v[0]=0;
		v[1]=1;
		t=a[i]-1;
		fore(j,i+1,n){
			v[j-i+1]+=t;
			if(v[j-i+1]>=MOD)v[j-i+1]-=MOD;
			t=(t*a[j])%MOD;
		}
	}
	fore(i,1,2*n-1)printf("%lld%c",r[i]*((MOD+1)/2)%MOD," \n"[i==2*n-2]);
	return 0;
}