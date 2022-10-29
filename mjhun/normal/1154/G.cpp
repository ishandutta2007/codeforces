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

#define M 10000005

int w[M];
int n;
pair<ll,pair<int,int> > r=mp(1LL<<60,mp(0,0));

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		if(w[a])r=min(r,mp(1LL*a,mp(w[a],i+1)));
		w[a]=i+1;
	}
	fore(i,1,M){
		int k=-1;
		for(int j=i;j<M;j+=i)if(w[j]){
			if(k<0)k=j;
			else {
				r=min(r,mp(1LL*k*j/i,mp(w[k],w[j])));
				break;
			}
		}
	}
	int a=r.snd.fst,b=r.snd.snd;
	if(a>b)swap(a,b);
	printf("%d %d\n",a,b);
	return 0;
}