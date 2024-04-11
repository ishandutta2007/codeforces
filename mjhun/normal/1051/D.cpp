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

#define MOD 998244353
int f[1024][2048][4];// columnas, componentes, estado

void add(int& a, int b){
	a+=b;
	if(a>=MOD)a-=MOD;
}

int main(){
	int n,kk;
	scanf("%d%d",&n,&kk);
	f[1][1][0]=f[1][1][3]=f[1][2][1]=f[1][2][2]=1;
	for(int i=1;i<n;++i){
		fore(j,0,2005){
			fore(k,0,4){
				add(f[i+1][j+(k==3)][0],f[i][j][k]);
				add(f[i+1][j+((k&1)!=(1&1))+((k&2)!=(1&2))][1],f[i][j][k]);
				add(f[i+1][j+((k&1)!=(2&1))+((k&2)!=(2&2))][2],f[i][j][k]);
				add(f[i+1][j+(k==0)][3],f[i][j][k]);
			}
		}
	}
	int r=0;
	fore(i,0,4)add(r,f[n][kk][i]);
	printf("%d\n",r);
	return 0;
}