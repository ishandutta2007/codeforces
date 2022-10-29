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
#define j0 PENAZZI
using namespace std;
typedef long long ll;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}

int b[1024][1024];int n,m;
bool v[1024][1024];
int i0=-1,j0,q,g;

bool valid(int k){
	fore(i,1,n+1)fore(j,1,m+1)if(b[i][j]&&i%k!=i0%k&&j%k!=j0%k)return false;
	return true;
}

void dfs(int i, int j){
	if(v[i][j]||!b[i][j])return;
	v[i][j]=true;
	dfs(i-1,j);dfs(i+1,j);dfs(i,j-1);dfs(i,j+1);
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,1,n+1)fore(j,1,m+1)scanf("%d",&b[i][j]);
	fore(i,1,n+1)fore(j,1,m+1)if(b[i][j]){
		if(i0<0)i0=i,j0=j;
		q+=b[i-1][j]^b[i+1][j]^b[i][j-1]^b[i][j+1];
	}
	if(q>2){puts("-1");return 0;}
	dfs(i0,j0);
	fore(i,1,n+1)fore(j,1,m+1)if(b[i][j]&&!v[i][j]){puts("-1");return 0;}
	fore(i,1,n+1){
		int j0=1;
		while(j0<=m){
			while(j0<=m&&!b[i][j0])j0++;
			if(j0>m)break;
			int j1=j0;
			while(b[i][j1])j1++;
			g=gcd(g,j1-j0-1);
			j0=j1;
		}
	}
	fore(j,1,m+1){
		int i0=1;
		while(i0<=n){
			while(i0<=n&&!b[i0][j])i0++;
			if(i0>n)break;
			int i1=i0;
			while(b[i1][j])i1++;
			g=gcd(g,i1-i0-1);
			i0=i1;
		}
	}
	if(g==0){puts("-1");return 0;}
	bool p=false;
	fore(i,2,g+1)if(g%i==0&&valid(i)){
		if(p)putchar(' ');
		printf("%d",i);
		p=true;
	}
	puts(p?"":"-1");
	return 0;
}