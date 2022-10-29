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

int d[100005];
int nd[100005];
int r;
int n;

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int p;
		scanf("%d",&p);p--;
		d[i]=d[p]+1;
	}
	fore(i,0,n)nd[d[i]]^=1;
	fore(i,0,n+1)r+=nd[i];
	printf("%d\n",r);
	return 0;
}