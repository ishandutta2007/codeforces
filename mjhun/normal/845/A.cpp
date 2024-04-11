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
using namespace std;
typedef long long ll;

int x[256];int n;

int main(){
#ifdef DEMETRIO
	freopen("ain","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF){
		fore(i,0,2*n)scanf("%d",x+i);
		sort(x,x+2*n);
		puts(x[n-1]==x[n]?"NO":"YES");

		puts("");
	}
	return 0;
}