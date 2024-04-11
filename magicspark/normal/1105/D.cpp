#include<bits/stdc++.h>
#define pb push_back
#define rep(i,n) for (int i=0;i<(n);++i)
#define rep1(i,n) for (int i=1;i<=(n);++i)
#define Rep(i,a,b) for (int i=(a);i<=(b);++i)
#define All(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define fillset(a,val) memset(a,val,sizeof(a))
#define X first
#define Y second
#define endl '\n'
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
namespace fastio{
	char in[100000];
	int itr=0,llen=0;
	char get(){
		if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
		if(llen==0)return EOF;
		return in[itr++];
	}
	char out[100000];
	int itr2=0;
	void put(char c){
		out[itr2++]=c;
		if(itr2==100000){
			fwrite(out,1,100000,stdout);
			itr2=0;
		}
	}
	int clear(){
		fwrite(out,1,itr2,stdout);
		itr2=0;
		return 0;
	}
	int getint(){
    	int r=0; bool ng=0; char c; c=get();
    	while (c!='-'&&(c<'0'||c>'9')) c=get();
   		if (c=='-') ng=1, c=get();
    	while (c>='0'&&c<='9') r=r*10+c-'0', c=get();
    	return ng?-r:r;
	}
	string getstr(){
		string ret="";
		char ch=get();
		while(ch==' '||ch=='\n')ch=get();
		while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
		return ret;
	}
	void putstr(string s){
		for(int i=0;i<s.size();i++)put(s[i]);
	}
	void putint(int x){
		if(x<0){
			put('-');
			x=-x;
		}
		if(x==0){
			put('0');
			return;
		}
		char c[20];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
	void getarr(int arrname[],int size){
		 for(int i=0;i<size;i++)arrname[i]=getint();
	}
}
using namespace fastio;
#define fastio
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
const int Maxn=1003;
int col[Maxn][Maxn];
string s[Maxn];
int n,m,p,spd[10],rest;
queue <int> q[10];
int vis[Maxn][Maxn];
inline bool ins(int x,int y){return x>=0&&y>=0&&x<n&&y<m;}
inline void bfs(int sx,int sy)
{
	queue <int> que;
	que.push(sx),que.push(sy);
	while (!que.empty())
	{
		int x=que.front();que.pop();
		int y=que.front();que.pop();
		if (vis[x][y]) continue;
		vis[x][y]=1;
		rep(i,4)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if (!ins(nx,ny) || s[nx][ny]=='#') continue;
			que.push(nx);que.push(ny);
		}
	}
}
int dist[Maxn][Maxn];
int main()
{
	n=getint();m=getint();p=getint();rest=n*m;
	rep1(i,p) spd[i]=getint();
	rep(i,n) s[i]=getstr();
	rep(i,n) rep(j,m) if (s[i][j]>'0' && s[i][j]<='9') bfs(i,j);
	rep(i,n) rep(j,m) if (vis[i][j]==0) col[i][j]=-1,rest--;
	rep(i,n) rep(j,m) if (isdigit(s[i][j]))
	{
		rest--;
		q[s[i][j]-'0'].push(i);
		q[s[i][j]-'0'].push(j);
		col[i][j]=s[i][j]-'0';
	}
	for (int t=1;rest;t=t%p+1)
	{
		queue <int> que;que=q[t];
		while (!que.empty())
		{
			int x=que.front();que.pop();
			int y=que.front();que.pop();
			dist[x][y]=0;
		}
		while (!q[t].empty())
		{
			int x=q[t].front();q[t].pop();
			int y=q[t].front();q[t].pop();
			if (dist[x][y]>=spd[t]) continue;
			rep(i,4)
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(!ins(nx,ny)||col[nx][ny])continue;
				q[t].push(nx);q[t].push(ny);
				dist[nx][ny]=dist[x][y]+1;
				col[nx][ny]=t;rest--;
				if (dist[nx][ny]==spd[t]) que.push(nx),que.push(ny);
			}
		}
		q[t]=que;
	}
	int cnt[10];
	memset(cnt,0,sizeof(cnt));
	rep(i,n)rep(j,m)if(col[i][j]>0)cnt[col[i][j]]++;
	rep1(i,p)cout<<cnt[i]<<" ";cout<<endl;
	return 0;
}