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

const int MAXN=200005;

//St Iterativo
#define oper min
#define NEUT (1ll<<30)
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

STree st(MAXN);

ll nxt[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			nxt[i]=(i+1)%n;
			//prv[nxt[i]]=i;
			if(__gcd(a[i],a[nxt[i]])==1){
				st.upd(i,i);
				st.upd(n+i,n+i);
			}else{
				st.upd(i,NEUT);
				st.upd(n+i,NEUT);
			}
		}
		vector<ll> res;
		ll va=0;
		while(1){
			/*
			cout<<va<<"\n";
			fore(i,0,2*n)cout<<st.query(i,i+1)<<" ";
			cout<<"\n";
			fore(i,0,n)cout<<nxt[i]<<" ";
			cout<<"\n";
			*/
			auto q=st.query(va,va+n);
			if(q==NEUT)break;
			if(q>=n)q-=n;
			if(nxt[q]==q){
				if(a[q]==1)res.pb(q);
				break;
			}
			res.pb(nxt[q]);
			st.upd(nxt[q],NEUT);
			st.upd(nxt[q]+n,NEUT);
			nxt[q]=nxt[nxt[q]];
			if(__gcd(a[q],a[nxt[q]])==1){
				st.upd(q,q);
				st.upd(n+q,n+q);
			}else{
				st.upd(q,NEUT);
				st.upd(n+q,NEUT);
			}
			va=nxt[q];
		}
		cout<<SZ(res)<<" ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}