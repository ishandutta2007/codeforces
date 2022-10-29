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

int n,m,k,s;
int w[16][4];
bool h[16][16];

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	fore(i,0,k)fore(j,0,4)w[i][j]=-(1<<29);
	fore(i,0,n)fore(j,0,m){
		int x;
		scanf("%d",&x);x--;
		w[x][0]=max(w[x][0],i+j);
		w[x][1]=max(w[x][1],i-j);
		w[x][2]=max(w[x][2],-i-j);
		w[x][3]=max(w[x][3],-i+j);
	}
	int p=-1;
	fore(i,0,s){
		int x;
		scanf("%d",&x);x--;
		if(i)h[x][p]=h[p][x]=1;
		p=x;
	}
	int r=0;
	fore(i,0,k)fore(j,0,k)if(h[i][j])fore(l,0,2)r=max(r,w[i][l]+w[j][l+2]);
	printf("%d\n",r);
	return 0;
}