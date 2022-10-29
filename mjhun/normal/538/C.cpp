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

void perdi(){puts("IMPOSSIBLE");exit(0);}

int n,m;
int d[100005],h[100005],r;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d%d",d+i,h+i),d[i]--;
	r=max(h[0]+d[0],h[m-1]+n-1-d[m-1]);
	fore(i,0,m-1){
		int dd=d[i+1]-d[i];
		int a=min(h[i],h[i+1]),b=max(h[i],h[i+1]);
		if(b-a>dd)perdi();
		//printf("%d %d %d\n",dd,b,a);
		r=max(r,b+(dd-b+a)/2);
	}
	printf("%d\n",r);
	return 0;
}