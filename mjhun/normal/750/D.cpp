#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

bool vis[305][305][32][8];
bool rr[305][305];
int t[32];
int n;

void go(int x, int y, int l, int d){
	if(vis[x][y][l][d])return;
	vis[x][y][l][d]=true;
	rr[x][y]=true;
	fore(_,0,t[l]-1){
		x+=dx[d];
		y+=dy[d];
		rr[x][y]=true;
	}
	if(l<n-1){
		int d0=(d+7)%8;
		int d1=(d+1)%8;
		go(x+dx[d0],y+dy[d0],l+1,d0);
		go(x+dx[d1],y+dy[d1],l+1,d1);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",t+i);
	go(152,152,0,0);
	int r=0;
	fore(i,0,305)fore(j,0,305)r+=rr[i][j];
	printf("%d\n",r);
	return 0;
}