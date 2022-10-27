#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[N<<1];int hd[N],S;
void add(int fr,int to,int w){
    e[++S]=(edge){to,hd[fr],w},hd[fr]=S;
}

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int mp[400];
int dis[N];
void solve(){
	mp['U']=0,mp['D']=1,mp['L']=2,mp['R']=3;
	int n,m,pp,Q;cin>>n>>m>>pp>>Q;
	vector<string> s(n+1);
	auto P=[&](int x,int y){
		return (x-1)*m+y;
	};
	for(int i=1;i<=n;i++)cin>>s[i],s[i]='0'+s[i];
	vector<int> ept;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')
				ept.push_back(P(i,j));
			if(s[i][j]=='#'||s[i][j]=='.')continue;
			int nk=mp[s[i][j]];
			int x=i+dx[nk],y=j+dy[nk];
			for(int k=0;k<4;k++){
				int a=i+dx[k],b=j+dy[k];
				if(a<=0||a>n)continue;
				if(b<=0||b>m)continue;
				if(k==mp[s[i][j]])continue;
				if(s[a][b]=='#')continue;
				if((k^mp[s[i][j]])==1){
					add(P(a,b),P(x,y),Q);
					//add(P(x,y),P(a,b),Q);
				}else{
					add(P(a,b),P(x,y),pp);
					//add(P(x,y),P(a,b),pp);
				}
			}
		}
	priority_queue<pair<int,int>> q;
	memset(dis,1,sizeof(dis));
	for(auto x:ept){
		dis[x]=0;
		q.push({0,x});
	}
	while(q.size()){
		int nw=q.top().second,w=q.top().first;
		q.pop();
		if(dis[nw]!=-w)continue;
		fore(nw)if(e[i].w+dis[nw]<dis[_to]){
			dis[_to]=e[i].w+dis[nw];
			q.push({-dis[_to],_to});
		}
	}
	int res=1e18;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#')continue;
			for(int k=0;k<4;k++){
				int a=i+dx[k],b=j+dy[k];
				if(a<=0||a>n)continue;
				if(b<=0||b>m)continue;
				if(s[a][b]=='#')continue;
				res=min(res,dis[P(i,j)]+dis[P(a,b)]);
			}
		}
	if(res>1e16)cout<<-1<<endl;
	else cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}