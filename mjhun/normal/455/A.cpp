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

int q[100005];int n;
ll f[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		q[x]++;
	}
	f[0]=f[1]=0;
	fore(i,2,100005)f[i]=max(f[i-1],1LL*q[i-1]*(i-1)+f[i-2]);
	printf("%lld\n",f[100004]);
	return 0;
}