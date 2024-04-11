#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
char b[1505][1505];
bool v[1505][1505];
int cx[1505][1505];
int cy[1505][1505];
bool r;

void dfs(int x, int y){
	v[x][y]=true;
	fore(dx,-1,2)
	fore(dy,-1,2){
		if(dx*dy!=0||dx+dy==0)continue;
		int x0=x+dx,y0=y+dy;
		int cx0=cx[x][y],cy0=cy[x][y];
		if(x0<0){x0=n-1;cx0++;}
		if(x0>n-1){x0=0;cx0--;}
		if(y0<0){y0=m-1;cy0++;}
		if(y0>m-1){y0=0;cy0--;}
		if(!b[x0][y0])continue;
		if(!v[x0][y0]){
			cx[x0][y0]=cx0;
			cy[x0][y0]=cy0;
			dfs(x0,y0);
		}
		else if(cx[x0][y0]!=cx0||cy[x0][y0]!=cy0)r=true;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	fore(i,0,n){
		scanf("%s",b[i]);
		fore(j,0,m){
			if(b[i][j]=='S')x=i,y=j;
			b[i][j]=b[i][j]!='#';
		}
	}
	dfs(x,y);
	puts(r?"Yes":"No");
	return 0;
}