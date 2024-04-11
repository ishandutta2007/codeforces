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

int n;
int mx[200005];
int q[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",q+i);
		fore(_,0,q[i]){
			int t;
			scanf("%d",&t);
			mx[i]=max(mx[i],t);
		}
	}
	int w=*max_element(mx,mx+n);
	ll r=0;
	fore(i,0,n)r+=1LL*(w-mx[i])*q[i];
	printf("%lld\n",r);
	return 0;
}