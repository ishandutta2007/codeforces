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

set<pair<int,int> > e;
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(x>y)swap(x,y);
		e.insert(mp(x,y));
	}
	if(m==n*(n-1)/2){puts("NO");return 0;}
	int a=-1,b=-1;
	fore(i,0,n){
		fore(j,i+1,n)if(!e.count(mp(i,j))){a=i;b=j;break;}
		if(a>=0)break;
	}
	assert(a>=0);
	puts("YES");
	int t=1;
	fore(i,0,n){
		if(i)putchar(' ');
		if(i==a)printf("%d",n-1);
		else if(i==b)printf("%d",n);
		else printf("%d",t++);
	}
	puts("");
	t=1;
	fore(i,0,n){
		if(i)putchar(' ');
		if(i==a||i==b)printf("%d",n);
		else printf("%d",t++);
	}
	puts("");
	return 0;
}