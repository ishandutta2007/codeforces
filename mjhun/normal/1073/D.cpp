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
using namespace std;
typedef long long ll;

int n,q;ll t,r;
ll a[200005];
int le[200005],ri[200005];

int main(){
	scanf("%d%lld",&n,&t);
	q=n;
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,n)le[i]=i-1,ri[i]=i+1;
	le[0]=n;ri[n]=0;le[n]=n-1;
	ll mn=*min_element(a,a+n);
	while(t>=mn){
		ll s=0;
		for(int i=ri[n];i<n;i=ri[i]){
			s+=a[i];
		}
		ll ss=0;ll w=1LL<<60;
		for(int i=ri[n];i<n;i=ri[i]){
			ss+=a[i];
			w=min(w,max((t-ss+s)/s,0LL));
		}
		t-=w*s;r+=w*q;
		for(int i=ri[n];i<n;i=ri[i]){
			if(t>=a[i])t-=a[i],s+=a[i],r++;
			else le[ri[i]]=le[i],ri[le[i]]=ri[i],q--;
		}
	}
	printf("%lld\n",r);
	return 0;
}