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

//St Iterativo
#define oper max
#define NEUT -1
struct STree{
	vector<int> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, int value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STree str(200005);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		set<ll> st;
		fore(i,0,n)st.insert(i);
		vector<ll> res(n);
		fore(i,0,n)res[i]=-1;
		fore(i,0,n){
			if(i==0||a[i-1]!=a[i]){
				res[i]=a[i];
				st.erase(res[i]);
			}
		}
		fore(i,0,n){
			if(res[i]==-1){
				ll mini=*st.begin();
				cout<<mini+1<<" ";
				st.erase(mini);
			}else cout<<res[i]+1<<" ";
		}
		cout<<"\n";
		fore(i,0,n)str.upd(i,i);
		fore(i,0,n){
			if(res[i]==-1){
				ll maxi=str.query(0,a[i]);
				cout<<maxi+1<<" ";
				str.upd(maxi,-1);
			}else{
				cout<<res[i]+1<<" ";
				str.upd(res[i],-1);
			}
		}
		cout<<"\n";
	}
	
	return 0;
}