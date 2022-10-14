#include<bits/stdc++.h>
using namespace std;
int const N=3010,M=600010,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int n,m,q,ans,cur,f[M],ord[N][N*2];
int newnode(){
	return cur++,f[cur]=cur,cur;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx^fy)f[fx]=fy;
}
int check(int x,int y){
	return find(x)==find(y);
}
void upd(int x,int y){
	ord[x][y]=newnode();
	for(int i=0;i<8;i++){
		int tx=x+dx[i],ty=(y+dy[i]+2*m)%(2*m);
		if(tx<0||tx>n||!ord[tx][ty])continue;
		merge(cur,ord[tx][ty]);
	} 
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	if(m<2)
		cout<<"0\n",exit(0);
	while(q--){
		int x,y,flg=1;cin>>x>>y;
		for(int i=0;i<8&&flg;i++)
			for(int j=0;j<8&&flg;j++){
				int px=x+dx[i],py=(y+dy[i]+2*m)%(2*m),
					qx=x+dx[j],qy=(y+dy[j]+m)%(2*m);
				if(px<0||px>n||qx<0||qx>n||!ord[px][py]||!ord[qx][qy])
					continue;
				flg&=!check(ord[px][py],ord[qx][qy]);
			}
		if(flg)
			ans++,upd(x,y),upd(x,(y+m)%(2*m));
	}
	cout<<ans<<"\n";
}