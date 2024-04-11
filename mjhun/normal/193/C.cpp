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

void perdi(){puts("-1");exit(0);}

int d12,d13,d14,d23,d24,d34;
char r[4][1<<20];int n,xx,yy;

bool doit(){
	int x,y,z;
	if((d14+d24-d12)%2)return false;
	z=(d14+d24-d12)/2;
	if((-d24+d12-d34+xx+yy)%2)return false;
	x=(-d24+d12-d34+xx+yy)/2;
	y=d14-x-z;
	if(x<0||y<0||z<0||x+y>d12||x>xx||z>yy||y>d12-xx)return false;
	fore(i,0,x)r[3][i]++;
	fore(i,xx,xx+y)r[3][i]++;
	fore(i,d12,d12+z)r[3][i]++;
	return true;
}

int main(){
	scanf("%d%d%d%d%d%d",&d12,&d13,&d14,&d23,&d24,&d34);
	memset(r,'a',sizeof(r));
	fore(i,0,d12)r[1][i]++;
	if((d13+d23-d12)%2)perdi();
	yy=(d13+d23-d12)/2;
	xx=d13-yy;
	if(xx<0||yy<0||xx>d12)perdi();
	fore(i,0,xx)r[2][i]++;
	fore(i,d12,d12+yy)r[2][i]++;
	n=d12+yy;
	while(d14>=0&&d24>=0&&d34>=0&&!doit()){
		d14--;d24--;d34--;
		r[3][n++]++;
	}
	if(d14<0||d24<0||d34<0)perdi();
	printf("%d\n",n);
	fore(i,0,4)r[i][n]=0,puts(r[i]);
	return 0;
}