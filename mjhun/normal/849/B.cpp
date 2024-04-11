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

ll x[1024],y[1024];
int n;

bool has(int i, int j, ll x1, ll y1){
	ll x0=x[j]-x[i],y0=y[j]-y[i];
	return x0*y1==x1*y0;
}

int	 main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",y+i),x[i]=i;
	fore(_,0,2){
		fore(i,1,n){
			bool c=true;
			int k=-1;
			fore(j,1,n){
				if(has(0,j,x[i]-x[0],y[i]-y[0]))continue;
				if(k<0)k=j;
				else if(!has(k,j,x[i]-x[0],y[i]-y[0])){c=false;break;}
			}
			if(c&&k>=0){
				puts("Yes");
				return 0;
			}
		}
		swap(y[0],y[1]);swap(x[0],x[1]);
	}
	puts("No");
	return 0;
}