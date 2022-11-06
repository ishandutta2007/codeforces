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

vector<ll> oc[26];

#define oper(a,b) a+b
#define NEUT 0
struct STree{
	vector<int> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
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

int main(){FIN;
	ll tcs; cin>>tcs;
	while(tcs--){
		ll n; cin>>n;
		string s,t; cin>>s>>t;
		auto ss=s;
		sort(ALL(ss));
		if(t<=ss){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,26)oc[i].clear();
		fore(i,0,SZ(s))oc[s[i]-'a'].pb(i);
		//fore(i,0,26)oc[i].pb(SZ(s));
		ll pos[26];
		mset(pos,0);
		STree st(n);
		fore(i,0,n)st.upd(i,1);
		ll res=1e18,va=0;
		fore(i,0,n){
			ll c=t[i]-'a';
			fore(j,0,c){
				if(pos[j]<SZ(oc[j])){
					res=min(res,va+st.query(0,oc[j][pos[j]]));
				}
			}
			if(pos[c]==SZ(oc[c]))break;
			va+=st.query(0,oc[c][pos[c]]);
			st.upd(oc[c][pos[c]],0);
			pos[c]++;
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}