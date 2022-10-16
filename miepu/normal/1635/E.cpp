#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[N];int hd[N],S=1;
int type[N];
void add(int fr,int to,int ty){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
    type[S>>1]=ty;
}

vector<int> ed[N];
int in[N];
int n,m,ans[N];
int col[N];//1 left 2 right
int il; 

void dfs(int k,int c){
	col[k]=c;
	fore(k){
		if(col[_to]){
			if(col[_to]!=3-c)il=1;
		}else
			dfs(_to,3-c);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		add(y,z,x),add(z,y,x);
	}
	for(int i=1;i<=n;i++){
		if(!col[i])dfs(i,1);
	}
	if(il)cout<<"NO",exit(0);
	for(int i=1;i<=m;i++){
		int y=e[i<<1].to,x=e[i<<1|1].to;
		if(type[i]==1){
			if(col[x]==1)swap(x,y);
			ed[x].push_back(y);
			in[y]++;
		}else{
			if(col[x]==2)swap(x,y);
			ed[x].push_back(y);
			in[y]++;
		}
	}
	int cnt=0;
	queue<int> q; 
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(q.size()){
		int nw=q.front();q.pop();
		cnt++;
		ans[nw]=n-cnt;
		for(auto x:ed[nw]){
			in[x]--;
			if(!in[x])q.push(x); 
		}
	}
	if(cnt!=n)cout<<"NO",exit(0);
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){
		cout<<(col[i]==1?'L':'R')<<' ';
		cout<<ans[i]<<'\n';
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}