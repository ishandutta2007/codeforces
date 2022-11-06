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

ll ask(ll l, ll r){
	cout<<"? 2 "<<l+1<<" "<<r+1<<endl;
	ll res; cin>>res;
	assert(res);
	return res;
}

char ask(ll x){
	cout<<"? 1 "<<x+1<<endl;
	char res; cin>>res;
	assert(res);
	return res;
}

/*----------------DSU------------------*/
const int MAXN=2020;
int pa[MAXN],sz[MAXN];
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

ll comp(ll l, ll r){
	vector<ll> v;
	fore(i,l,r){
		v.pb(find_pa(i));
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	return SZ(v);
}

vector<ll> filt(vector<ll> s, ll c){
	vector<ll> res;
	for(auto i:s){
		if(i!=c)res.pb(i);
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	dsu_init(n);
	vector<ll> v={0};
	fore(i,1,n){
		ll l=0,r=SZ(v)-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(v[m],i)==comp(v[m],i))l=m+1;
			else r=m-1;
		}
		if(r==-1)v.pb(i);
		else{
			join(i,v[r]);
			v=filt(v,v[r]);
			v.pb(i);
		}
	}
	string s;
	for(auto i:v)s.pb(ask(i));
	string res;
	fore(i,0,n){
		fore(j,0,SZ(v)){
			if(find_pa(i)==find_pa(v[j]))res+=s[j];
		}
	}
	cout<<"! "<<res<<"\n";
	
	return 0;
}