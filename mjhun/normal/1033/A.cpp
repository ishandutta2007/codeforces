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

bool r=true;

void doit(int a, int b, int c){
	r=r&&((b>a)==(c>a));
}

int main(){
	int n,ax,ay,bx,by,cx,cy;
	scanf("%d%d%d%d%d%d%d",&n,&ax,&ay,&bx,&by,&cx,&cy);
	doit(ax,bx,cx);
	doit(ay,by,cy);
	//doit(ax+ay,bx+by,cx+cy);
	//doit(ax-ay,bx-by,cx-cy);
	puts(r?"YES":"NO");
	return 0;
}