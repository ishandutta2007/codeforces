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

const int MAXN=200005;

set<ll> st;

ll t[MAXN],tc[MAXN];

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper max
#define NEUT -1
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

STree stm(MAXN);

void rem(ll l, ll r, ll ti){
	while(1){
		auto it=st.lower_bound(l);
		if(it==st.end())break;
		auto b=*it;
		if(b<=r){
			t[b]=ti;
			stm.upd(b,ti);
			st.erase(b);
		}else break;
	}
}

ll getel(ll l, ll r){
	auto it=st.lower_bound(l);
	if(it==st.end())return -1;
	auto res=*it;
	if((st.lower_bound(res+1)!=st.end())&&*st.lower_bound(res+1)<=r)return -1;
	return res;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<pair<ll,ll>> vq;
	vector<pair<pair<ll,ll>,ll>> vo;
	fore(i,0,n)st.insert(i);
	fore(i,0,q){
		ll ty; cin>>ty;
		if(ty){
			ll pos; cin>>pos; pos--;
			vq.pb({pos,i});
		}else{
			ll l,r,x; cin>>l>>r>>x; l--; r--;
			if(x){
				vo.pb({{l,r},i});
			}else{
				rem(l,r,i);
			}
		}
	}
	vector<ll> res(SZ(vq),0);
	fore(i,0,SZ(vq)){
		if(!st.count(vq[i].fst)&&t[vq[i].fst]<vq[i].snd)res[i]=-1;
	}
	fore(i,0,n)tc[i]=MAXN;
	fore(i,0,SZ(vo)){
		auto q=getel(vo[i].fst.fst,vo[i].fst.snd);
		if(q!=-1){
			ll val=max(vo[i].snd,stm.query(vo[i].fst.fst,vo[i].fst.snd+1));
			tc[q]=min(tc[q],val);
		}
	}
	fore(i,0,SZ(vq)){
		if(tc[vq[i].fst]<vq[i].snd)res[i]=1;
	}
	for(auto i:res){
		if(i==1)cout<<"YES\n";
		if(i==0)cout<<"N/A\n";
		if(i==-1)cout<<"NO\n";
	}
	return 0;
}