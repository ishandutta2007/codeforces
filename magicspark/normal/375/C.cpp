/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
string s[22];
int v[888];
int grid[22][22];
//0->empty
//x->value
//-1->#
//-inf->bomb
int sx,sy;
vector<pair<int,int> >M;
int dist[21][21][1<<8];
struct state{
	int x,y,mask,dist;
	state(int xx,int yy,int mmask,int ddist){x=xx;y=yy;mask=mmask;dist=ddist;}
};
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
const int Dx=77,Dy=76;
int update(int mask,int x,int y,int xx,int yy){
	for(int i=0;i<M.size();i++){
		if(x==xx){
			int L=min(y,yy)*Dx,R=max(y,yy)*Dx,f=Dx*M[i].second+Dy*(x-M[i].first);
			if(x<M[i].first)continue;
			if(L<=f&&f<=R)mask^=(1<<i);
		}else{
			int L=min(x,xx)*Dy,R=max(x,xx)*Dy,f=Dy*M[i].first+Dx*(y-M[i].second);
			if(y<M[i].second)continue;
			if(L<=f&&f<=R)mask^=(1<<i);
		}
	}
	return mask;
}
int get(int mask){
	int ret=0;
	for(int i=0;i<M.size();i++){
		if(mask&(1<<i)){
			ret+=grid[M[i].first][M[i].second]-123456;
		}
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=100;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		s[i]=" "+s[i];
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				grid[i][j]=0;
			}else if(s[i][j]=='S'){
				grid[i][j]=0;sx=i;sy=j;
			}else if(s[i][j]>='1'&&s[i][j]<='8'){
				grid[i][j]=v[s[i][j]-'0']+123456;
				M.push_back(make_pair(i,j));
			}else if(s[i][j]=='B'){
				grid[i][j]=-1e6;
				M.push_back(make_pair(i,j));
			}else if(s[i][j]=='#'){
				grid[i][j]=-1;
			}
		}
	}
	memset(dist,inf,sizeof dist);
	dist[sx][sy][0]=0;
	queue<state>q;
	q.push(state(sx,sy,0,0));
	while(!q.empty()){
		state st=q.front();q.pop();
//		cerr<<st.x<<" "<<st.y<<" "<<st.mask<<" "<<st.dist<<endl;
		for(int i=0;i<4;i++){
			int nx=st.x+dx[i],ny=st.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m)continue;
			if(grid[nx][ny])continue;
			if(dist[nx][ny][update(st.mask,st.x,st.y,nx,ny)]>dist[st.x][st.y][st.mask]+1){
				dist[nx][ny][update(st.mask,st.x,st.y,nx,ny)]=dist[st.x][st.y][st.mask]+1;
				q.push(state(nx,ny,update(st.mask,st.x,st.y,nx,ny),dist[nx][ny][update(st.mask,st.x,st.y,nx,ny)]));
			}
		}
	}
	int ans=0;
	for(int mask=0;mask<(1<<M.size());mask++){
		int res=get(mask)-dist[sx][sy][mask];
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}