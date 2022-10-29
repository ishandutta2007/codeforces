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
#define MOD 1000000007
using namespace std;
typedef long long ll;

int b[1024][1024];
map<ll,int> c;
ll a[1024];
int m,n;
char s[1024];

int main(){
	b[0][0]=1;
	fore(i,1,1024){
		b[i][0]=b[i-1][i-1];
		fore(j,1,i+1)b[i][j]=(b[i][j-1]+b[i-1][j-1])%MOD;
	}
	scanf("%d%d",&m,&n);
	fore(i,0,n){
		scanf("%s",s);
		fore(j,0,m)if(s[j]=='1')a[j]|=1LL<<i;
	}
	fore(i,0,m)c[a[i]]++;
	int r=1;
	for(auto p:c)r=(1LL*r*b[p.snd][0])%MOD;
	printf("%d\n",r);
	return 0;
}