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

/*---------------- Union Find (DSU) ------------------*/
const ll N=1e6+10;
int pa[N],sz[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

void term(){
	cout<<"INVALID"; exit(0);
}

ll n;
ll vis[1010][1010];
ll val(ll i, ll j){
	return i>=0&&i<n&&j>=0&&j<n;
}

int main(){FIN;
	cin>>n;
	pair<ll,ll> a[n][n];
	fore(i,0,n){
		fore(j,0,n){
			cin>>a[i][j].fst>>a[i][j].snd; a[i][j].fst--,a[i][j].snd--;
		}
	}
	set<pair<ll,ll>> s;
	fore(i,0,n){
		fore(j,0,n){
			s.insert(a[i][j]);
		}
	}
	s.erase({-2,-2});
	char res[n][n];
	fore(i,0,n)fore(j,0,n)res[i][j]='.';
	for(auto i:s){
		if(a[i.fst][i.snd]!=i)term();
		res[i.fst][i.snd]='X';
		vis[i.fst][i.snd]=1;
		queue<pair<ll,ll>> q;
		q.push(i);
		while(SZ(q)){
			pair<ll,ll> t=q.front(); q.pop();
			if(val(t.fst+1,t.snd)&&!vis[t.fst+1][t.snd]&&a[t.fst+1][t.snd]==i){
				q.push({t.fst+1,t.snd});
				vis[t.fst+1][t.snd]=1;
				res[t.fst+1][t.snd]='U';
			}
			if(val(t.fst-1,t.snd)&&!vis[t.fst-1][t.snd]&&a[t.fst-1][t.snd]==i){
				q.push({t.fst-1,t.snd});
				vis[t.fst-1][t.snd]=1;
				res[t.fst-1][t.snd]='D';
			}
			if(val(t.fst,t.snd+1)&&!vis[t.fst][t.snd+1]&&a[t.fst][t.snd+1]==i){
				q.push({t.fst,t.snd+1});
				vis[t.fst][t.snd+1]=1;
				res[t.fst][t.snd+1]='L';
			}
			if(val(t.fst,t.snd-1)&&!vis[t.fst][t.snd-1]&&a[t.fst][t.snd-1]==i){
				q.push({t.fst,t.snd-1});
				vis[t.fst][t.snd-1]=1;
				res[t.fst][t.snd-1]='R';
			}
		}
	}
	pair<ll,ll> inf={-2,-2};
	fore(i,0,n){
		fore(j,0,n){
			if(!vis[i][j]&&a[i][j]!=inf)term();
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			if(!vis[i][j]){
				if(val(i+1,j)&&vis[i+1][j]==2){
					vis[i][j]=2;
					res[i][j]='D';
					continue;
				}
				if(val(i-1,j)&&vis[i-1][j]==2){
					vis[i][j]=2;
					res[i][j]='U';
					continue;
				}
				if(val(i,j+1)&&vis[i][j+1]==2){
					vis[i][j]=2;
					res[i][j]='R';
					continue;
				}
				if(val(i,j-1)&&vis[i][j-1]==2){
					vis[i][j]=2;
					res[i][j]='L';
					continue;
				}
				
				if(val(i+1,j)&&a[i+1][j]==inf){
					vis[i][j]=2;
					vis[i+1][j]=2;
					res[i][j]='D';
					res[i+1][j]='U';
					continue;
				}
				if(val(i-1,j)&&a[i-1][j]==inf){
					vis[i][j]=2;
					vis[i-1][j]=2;
					res[i][j]='U';
					res[i-1][j]='D';
					continue;
				}
				if(val(i,j+1)&&a[i][j+1]==inf){
					vis[i][j]=2;
					vis[i][j+1]=2;
					res[i][j]='R';
					res[i][j+1]='L';
					continue;
				}
				if(val(i,j-1)&&a[i][j-1]==inf){
					vis[i][j]=2;
					vis[i][j-1]=2;
					res[i][j]='L';
					res[i][j-1]='R';
					continue;
				}
				term();
			}
		}
	}
	cout<<"VALID\n";
	fore(i,0,n){
		fore(j,0,n){
			cout<<res[i][j];
		}
		cout<<"\n";
	}
	
	
	return 0;
}