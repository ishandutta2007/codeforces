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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
priority_queue<ll> w;
ll sv,st;
ll vv[100005],tt[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",vv+i);
	fore(i,0,n)scanf("%lld",tt+i);
	fore(i,0,n){
		ll v=vv[i],t=tt[i];
		w.push(-v-st);sv+=v;
		ll pv=sv;
		st+=t;sv-=t*SZ(w);
		while(!w.empty()&&-w.top()<=st){
			ll v=-w.top();w.pop();
			sv+=abs(v-st);
		}
		printf("%lld%c",pv-sv," \n"[i==n-1]);
	}

	return 0;
}