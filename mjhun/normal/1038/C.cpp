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
pair<int,int> x[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		x[i]=mp(t,0);
	}
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		x[n+i]=mp(t,1);
	}
	sort(x,x+2*n);reverse(x,x+2*n);
	ll s=0;
	fore(i,0,2*n){
		if(i%2==x[i].snd){
			if(i%2==0)s+=x[i].fst;
			else s-=x[i].fst;
		}
	}
	printf("%lld\n",s);
	return 0;
}