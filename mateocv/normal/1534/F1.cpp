#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=400004;

// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int nn,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,nn)if(!idx[i])tjn(i);
}

bool valid(ll x, ll y, ll n, ll m){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<string> t(n);
	fore(i,0,n)cin>>t[i];
	fore(j,0,m){
		ll pre=-1;
		fore(i,0,n){
			if(t[i][j]=='#'){
				pre=i;
			}else{
				if(pre!=-1)t[i][j]='&';
			}
		}
	}
	vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0}};
	auto dir2=dir;
	dir2.pop_back();
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]=='#'){
				for(auto ii:dir){
					ll x=i+ii.fst,y=j+ii.snd;
					if(valid(x,y,n,m)&&(t[x][y]=='#'||(ii.fst==1&&ii.snd==0))){
						g[m*i+j].pb(m*x+y);
					}
				}
			}else if(t[i][j]=='&'){
				for(auto ii:dir2){
					ll x=i+ii.fst,y=j+ii.snd;
					if(valid(x,y,n,m)&&(t[x][y]=='#'||(ii.fst==1&&ii.snd==0))){
						g[m*i+j].pb(m*x+y);
					}
				}
			}
		}
	}
	/*
	fore(i,0,m*n){
		for(auto j:g[i]){
			cout<<i/m<<" "<<i%m<<" -> "<<j/m<<" "<<j%m<<"\n";
		}
	}
	*/
	nn=n*m;
	scc();
	/*
	fore(i,0,n*m){
		cout<<i/m<<" "<<i%m<<" -> "<<cmp[i]<<"\n";
	}
	*/
	set<ll> st;
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]=='.')continue;
			st.insert(cmp[m*i+j]);
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			//if(t[i][j]=='.')continue;
			for(auto ii:g[m*i+j]){
				if(cmp[ii]!=cmp[m*i+j])st.erase(cmp[ii]);
			}
		}
	}
	cout<<SZ(st)<<"\n";
	return 0;
}