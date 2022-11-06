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
typedef int ll;

ll a[300005];

const int K=19;

#define oper min
int st[K][1<<K];int n;  // K such that 2^K>n
void st_init(int *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

ll vis[300005];
vector<ll> vvis;

bool solve(ll k){
	assert(k>=2);
	fore(i,0,n-k+1){
		ll mini=st_query(i,i+k);
		if(vis[mini]){
			for(auto i:vvis)vis[i]=0;
			vvis.clear();
			return 0;
		}
		vis[mini]=1;
		vvis.pb(mini);
	}
	fore(i,0,SZ(vvis)){
		if(vvis[i]>n-k){
			for(auto j:vvis)vis[j]=0;
			vvis.clear();
			return 0;
		}
	}
	for(auto i:vvis)vis[i]=0;
	vvis.clear();
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i],a[i]--;
		st_init(a);
		sort(a,a+n);
		ll br=0;
		fore(i,0,n-1){
			if(a[i]==a[i+1]){
				br++; break;
			}
		}
		string res(n,'0');
		if(!br)res[0]='1';
		ll l=2,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(m))r=m-1;
			else l=m+1;
		}
		fore(i,l-1,n)res[i]='1';
		cout<<res<<"\n";
	}
	
	return 0;
}