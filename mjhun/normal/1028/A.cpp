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

int n,m;
char b[128][128];

int main(){
	scanf("%d%d",&n,&m);
	int ai,bi,aj,bj;
	fore(i,0,n)scanf("%s",b[i]);
	fore(i,0,n)fore(j,0,m)if(b[i][j]=='B'){
		if(i==0||b[i-1][j]=='W')ai=i;
		if(i==n-1||b[i+1][j]=='W')bi=i;
		if(j==0||b[i][j-1]=='W')aj=j;
		if(j==m-1||b[i][j+1]=='W')bj=j;
	}
	printf("%d %d\n",(ai+bi)/2+1,(aj+bj)/2+1);
	return 0;
}