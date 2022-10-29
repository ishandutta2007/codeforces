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


int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a-b>1){puts("NO");continue;}
		bool p=true;
		a+=b;
		for(ll i=2;i*i<=a;++i)if(a%i==0){p=false;break;}
		puts(p?"YES":"NO");
	}
	return 0;
}