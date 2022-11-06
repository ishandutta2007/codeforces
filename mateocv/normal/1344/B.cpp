#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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

ll n,m; 

bool val(ll i, ll j){
	return (i>=0)&&(i<n)&&(j>=0)&&(j<m);
}

int main(){FIN;
	cin>>n>>m;
	char t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>t[i][j];
		}
	}
	dsu_init(n*m);
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]=='#'){
				if(val(i+1,j)&&t[i+1][j]=='#')join(m*i+j,m*(i+1)+j);
				if(val(i-1,j)&&t[i-1][j]=='#')join(m*i+j,m*(i-1)+j);
				if(val(i,j+1)&&t[i][j+1]=='#')join(m*i+j,m*i+j+1);
				if(val(i,j-1)&&t[i][j-1]=='#')join(m*i+j,m*i+j-1);
			}
		}
	}
	
	ll bf[n],bc[m];
	ll ef=0,ec=0;
	fore(i,0,n){
		ll tot=0;
		fore(j,0,m)tot+=(t[i][j]=='.');
		bf[i]=(tot==m);
		ef=max(ef,bf[i]);
	}
	fore(j,0,m){
		ll tot=0;
		fore(i,0,n)tot+=(t[i][j]=='.');
		bc[j]=(tot==n);
		ec=max(ec,bc[j]);
	}
	
	fore(i,0,n){
		set<ll> st;
		ll l=max(n,m),r=-1;
		fore(j,0,m){
			if(t[i][j]=='#'){
				st.insert(find_pa(m*i+j));
				l=min(l,j);
				r=max(r,j);
			}
		}
		if(SZ(st)>1||(SZ(st)==0&&ec==0)){
			cout<<-1;
			return 0;
		}
		if(SZ(st)){
			fore(j,l,r+1){
				if(t[i][j]=='.'){
					cout<<-1;
					return 0;
				}
			}	
		}
	}
	fore(j,0,m){
		set<ll> st;
		ll l=max(n,m),r=-1;
		fore(i,0,n){
			if(t[i][j]=='#'){
				st.insert(find_pa(m*i+j));
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(SZ(st)>1||(SZ(st)==0&&ef==0)){
			cout<<-1;
			return 0;
		}
		if(SZ(st)){
			fore(i,l,r+1){
				if(t[i][j]=='.'){
					cout<<-1;
					return 0;
				}
			}
		}
	}
	set<ll> st;
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]=='#')st.insert(find_pa(m*i+j));
		}
	}
	cout<<SZ(st);
	
	return 0;
}