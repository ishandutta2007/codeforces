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

#define MOD 1000000007

ll f[100005];

int main(){
	f[0]=1;
	f[1]=2;
	f[2]=4;
	fore(i,3,100005)f[i]=(f[i-2]+f[i-1])%MOD;
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld\n",(f[n]+f[m]+MOD-2)%MOD);
	return 0;
}