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

ll b[200005];
ll r[200005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n/2)scanf("%lld",b+i);
	r[0]=0;r[n-1]=b[0];
	fore(i,1,n/2){
		r[i]=r[i-1];
		r[n-1-i]=b[i]-r[i];
		if(r[n-1-i]>r[n-i]){
			r[n-1-i]=r[n-i];
			r[i]=b[i]-r[n-1-i];
		}
	}
	fore(i,0,n)printf("%lld%c",r[i]," \n"[i==n-1]);
	return 0;
}