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

int q[1024];int n,m;

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x;
		scanf("%d",&x);q[x-1]++;
	}
	int r=1<<30;
	fore(i,0,n)r=min(r,q[i]);
	printf("%d\n",r);
	return 0;
}