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
#define SZ(x) ((int)x.size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int q;
vector<ll> x,sp;

double asd(int i){
	return x.back()-1.*(sp[i]+x.back())/(i+1);
}

int main(){
	sp.pb(0);
	scanf("%d",&q);
	int i=0;
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			ll a;
			scanf("%lld",&a);
			x.pb(a);
			sp.pb(sp.back()+a);
		}
		else {
			while(i<SZ(x)-1&&asd(i)<asd(i+1))i++;
			printf("%.12lf\n",asd(i));
		}
	}
	return 0;
}