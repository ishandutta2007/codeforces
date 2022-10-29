#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
char r[128][128];
int x[128][128],y[128][128];

bool doit(int i, int j, char c){
	if(r[i-1][j]==c||r[i][j+1]==c)return false;
	if(r[i][j-1]==c){
		int xx=x[i][j-1],yy=y[i][j-1];
		if(xx!=i||xx+j-yy>n)return false;
		int s=j-yy+1;
		fore(ii,0,s){
			r[xx+ii][yy+s-1]=r[xx+s-1][yy+ii]=c;
			x[xx+ii][yy+s-1]=x[xx+s-1][yy+ii]=xx;
			y[xx+ii][yy+s-1]=y[xx+s-1][yy+ii]=yy;
		}
		return true;
	}
	else {
		r[i][j]=c;
		x[i][j]=i;y[i][j]=j;
		return true;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,1,n+1)fore(j,1,m+1){
		if(r[i][j])continue;
		char c='A';
		while(!doit(i,j,c))c++;
	}
	fore(i,1,n+1)puts(r[i]+1);
	return 0;
}