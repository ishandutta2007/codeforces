#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int sum[N];


struct edge{
	int to,nx,w; 
};

struct Flow{
	edge e[N];
	vector<int> hd;
	int n,S;
	void add(int fr,int to,int w){
		e[++S]={to,hd[fr],w},hd[fr]=S;
		e[++S]={fr,hd[to],0},hd[to]=S;
	}
	#define fore(k) for(int i=hd[k];i;i=e[i].nx)
	#define _to e[i].to
	#define fory(k) for(int&i=hy[k];i;i=e[i].nx) 
	Flow(int _n){
		n=_n;
		S=1;
		hd.resize(_n+1);
	}
	vector<int> hy,dep;
	bool bfs(int s,int t){
		hy=hd;
		dep.clear();dep.resize(n+1,-1);
		queue<int> q;
		dep[t]=N;
		q.push(t);
		while(q.size()){
			int nw=q.front();q.pop();
			fore(nw)if(e[i^1].w&&dep[_to]==-1){
				dep[_to]=dep[nw]-1;
				if(_to==s)return 1;
				q.push(_to);
			}
		}
		return 0;
	}
	int dfs(int k,int t,int fl){
		if(k==t)return fl;
		int nf=0;
		fory(k)if(dep[_to]==dep[k]+1&&e[i].w){
			int l=dfs(_to,t,min(e[i].w,fl));
			if(l==0)dep[k]=-1;
			nf+=l; 
			fl-=l;
			e[i].w-=l;
			e[i^1].w+=l;
			if(fl==0)break;
		}
		return nf;
	}
	int flow(int s,int t){
		int res=0;
		while(bfs(s,t))
			res+=dfs(s,t,1e9);
		return res;
	}
};

int n,m;
int s[N];
int a[N];
int u[N],v[N];
int c[N];
int fl[N];
int in[N],ou[N];

vector<pair<int,int>> A;
int id[N],mid[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0){
			in[0]+=a[i];
			ou[i]+=a[i];
		}else{
			ou[0]-=a[i];
			in[i]-=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		if(!s[u[i]]&&!s[v[i]])continue;
		if(!s[u[i]]||!s[v[i]]){
			if(s[u[i]])swap(u[i],v[i]);
			mid[A.size()]=i;
			A.push_back({0,v[i]});
			in[0]++;
			ou[v[i]]++;
		}else{
			mid[A.size()]=i;
			A.push_back({u[i],v[i]});
			in[u[i]]++;
			ou[v[i]]++;
		}
	}
	Flow E(n+5);
	int ss=n+1,tt=n+2;
	int sum=0;
	for(int i=0;i<=n;i++){
		if(in[i]+ou[i]&1){
			cout<<"NO"<<endl;
			return ;
		}
		if(in[i]>ou[i]){
			E.add(ss,i,(in[i]-ou[i])/2);
			sum+=in[i]-ou[i];
		}else{
			E.add(i,tt,(ou[i]-in[i])/2);
		}
	}
	sum/=2;
	int c=0;
	for(auto x:A){
		E.add(x.first,x.second,1);
		id[c++]=E.S;
	}
	int res=E.flow(ss,tt);
	if(res!=sum){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<'\n'; 
	for(int i=0;i<A.size();i++){
		if(E.e[id[i]].w){
			swap(u[mid[i]],v[mid[i]]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<' '<<u[i]<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}