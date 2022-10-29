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
vector<int> p;

void fact(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			p.pb(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)p.pb(n);
}

int main(){
	scanf("%d",&n);
	fact(n);
	if(SZ(p)==1){puts("NO");return 0;}
	puts("YES\n2");
	int p0=p[0],p1=p[1];
	if(p0>p1)swap(p0,p1);
	fore(i,1,p1)if((n-1-i*p0)%p1==0){
		int j=(n-1-i*p0)/p1;
		assert(j>0);
		printf("%d %d\n%d %d\n",i,n/p0,j,n/p1);
		return 0;
	}
	assert(0);
	return 0;
}