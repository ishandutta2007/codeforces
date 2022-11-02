#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=505;
const int M=3e5+5;
int dist[N][N],n,m;
bool vis[N][N];
queue<int>qx,qy;
int uu[M],vv[M],val[M];
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(LL x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Init(){
	n=Read(),m=Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	for(int i=1;i<=m;i++){
		uu[i]=Read();
		vv[i]=Read();
		val[i]=Read();
		vis[uu[i]][vv[i]]=vis[vv[i]][uu[i]]=1;
		//Add_Edge(uu[i],vv[i]);
	}
	return ;
}
inline void Upd(int u1,int u2,int dis){
	if(dist[u1][u2]<=dis) return ;
	dist[u1][u2]=dis;
	qx.push(u1),qy.push(u2);
	return ;
}
inline void Bfs(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[i][j]=0x3f3f3f3f;
	Upd(1,n,0);
	Upd(n,1,0);
	/*dist[2][5]=0;
	qx.push(2),qy.push(5);
	dist[5][2]=0;
	qx.push(5),qy.push(2);*/
	while(qx.size()){
		int u1=qx.front();
		int u2=qy.front();
		qx.pop(),qy.pop();
		int dis=dist[u1][u2];
		//printf("u1=%d u2=%d dis=%d\n",u1,u2,dis);
		//getchar();
		//Upd(u1,u1,dis+1);
		//Upd(u2,u2,dis+1);
		if(u1==u2){
			for(int i=1;i<=n;i++){
				Upd(u1,i,dis+1);
				Upd(i,u2,dis+1);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(vis[i][u2]){
					Upd(u1,i,dis+1);
				}
				if(vis[i][u1]){
					Upd(i,u2,dis+1);
				}
			}
		}
	}
	return ;
}
inline int Max(int x,int y){
	return x>y?x:y;
}
inline int Min(int x,int y){
	return x<y?x:y;
}
inline void Cmax(int&x,int y){
	if(y>x) x=y;
	return ;
}
inline void Cmin(LL&x,LL y){
	if(y<x) x=y;
	return ;
}
LL ans;
inline void Solve(){
	Bfs();
	ans=1ll<<60;
	//printf("%d\n",dist[1][n]);
	//printf("%d\n",dist[4][4][0]);
	for(int i=1;i<=m;i++)
		if(dist[uu[i]][vv[i]]!=-1)
			Cmin(ans,1ll*dist[uu[i]][vv[i]]*val[i]+val[i]);
	return Print(ans);
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}