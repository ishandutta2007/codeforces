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
const ll N=50;
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

int main(){FIN;
	ll n; cin>>n;
	string s[n];
	fore(i,0,n)cin>>s[i];
	dsu_init(26);
	set<ll> st;
	fore(i,0,n){
		fore(j,0,SZ(s[i])-1){
			join(s[i][j]-'a',s[i][j+1]-'a');
			st.insert(s[i][j]-'a');
		}
		st.insert(s[i][SZ(s[i])-1]-'a');
	}
	ll res=0;
	set<ll> stt;
	for(auto i:st){
		stt.insert(find_pa(i));
	}
	cout<<SZ(stt);
	return 0;
}