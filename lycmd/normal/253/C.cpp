#include<bits/stdc++.h>
using namespace std;
int const N=105,M=100010,INF=0x3f3f3f3f;
int n,sx,sy,ex,ey,a[N],d[N][M];
queue<pair<int,int> >q;
void up(int&x,int&y){
	if(x>1)y=min(y,a[--x]);
}
void down(int&x,int&y){
	if(x<n)y=min(y,a[++x]);
}
void left(int&x,int&y){
	y=min(y+1,a[x]);
}
void right(int&x,int&y){
	y=max(y-1,1);
}
void ins(int x,int y,int w){
	if(x==ex&&y==ey)
		cout<<w<<"\n",exit(0);
	if(d[x][y]>w)
		d[x][y]=w,q.push({x,y});
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]++;
	cin>>sx>>sy>>ex>>ey;
	memset(d,0x3f,sizeof d),ins(sx,sy,0);
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		int tx=x,ty=y;up(tx,ty),ins(tx,ty,d[x][y]+1);
		tx=x,ty=y;down(tx,ty),ins(tx,ty,d[x][y]+1);
		tx=x,ty=y;left(tx,ty),ins(tx,ty,d[x][y]+1);
		tx=x,ty=y;right(tx,ty),ins(tx,ty,d[x][y]+1);
	}
}