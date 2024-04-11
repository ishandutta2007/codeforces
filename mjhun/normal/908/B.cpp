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

int n,m,xs,ys;
char b[64][64],s[128];int l;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int p[4];

bool doit(){
	int x=xs,y=ys;
	fore(i,0,l){
		x+=dx[p[s[i]]];
		y+=dy[p[s[i]]];
		if(x<0||x>=n||y<0||y>=m||b[x][y]=='#')return false;
		if(b[x][y]=='E')return true;
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%s",b[i]);
	scanf("%s",s);l=strlen(s);
	fore(i,0,n)fore(j,0,m)if(b[i][j]=='S')xs=i,ys=j;
	fore(i,0,l)s[i]-='0';
	fore(i,0,4)p[i]=i;
	int r=0;
	do {
		r+=doit();
	} while(next_permutation(p,p+4));
	printf("%d\n",r);
	return 0;
}