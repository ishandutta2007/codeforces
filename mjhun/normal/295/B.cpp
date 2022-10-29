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

int n,f[512][512];
int p[512];
ll r[512];bool u[512];

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n)scanf("%d",&f[i][j]);
	fore(i,0,n)scanf("%d",p+i),p[i]--;
	for(int _=n-1;_>=0;--_){
		int k=p[_];u[k]=true;
		fore(i,0,n)fore(j,0,n){
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			if(u[i]&&u[j])r[_]+=f[i][j];
		}
	}
	fore(i,0,n)printf("%lld%c",r[i]," \n"[i==n-1]);
	return 0;
}