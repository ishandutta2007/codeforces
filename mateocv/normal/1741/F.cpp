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

ll n;

vector<pair<ll,ll>> a;
vector<ll> c;
vector<ll> res;
bool b=0;

#define oper max
#define NEUT -1e9
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

void rever(){
	for(auto &i:a){
		i.fst=1000000001-i.fst;
		i.snd=1000000001-i.snd;
		swap(i.fst,i.snd);
	}
	reverse(ALL(a));
	reverse(ALL(c));
	b^=1;
}

void solvepp(){
	vector<pair<ll,ll>> ev;
	fore(i,0,n){
		ev.pb({a[i].fst,i});
		ev.pb({a[i].snd,i});
	}
	sort(ALL(ev));
	STree st(n);
	for(auto i:ev){
		auto co=c[i.snd];
		ll resp=i.fst-max(st.query(0,co),st.query(co+1,n));
		res[(b?n-1-i.snd:i.snd)]=min(res[(b?n-1-i.snd:i.snd)],resp);
		st.upd(co,i.fst);
	}
}

void solvesg(){
	vector<pair<ll,ll>> ev;
	fore(i,0,n){
		ev.pb({a[i].fst,i});
		ev.pb({a[i].snd+1,-i-1});
	}
	sort(ALL(ev));
	vector<ll> ca(n,0);
	ll qc=0;
	STree st(n);
	for(auto i:ev){
		if(i.snd>=0){
			auto co=c[i.snd];
			if(qc>=2||(qc==1&&ca[co]==0)){
				res[(b?n-1-i.snd:i.snd)]=0;
			}
			if(ca[co]==0)qc++;
			ca[co]++;
		}else{
			auto co=c[-i.snd-1];
			if(qc>=2||(qc==1&&ca[co]==0)){
				res[(b?n+i.snd:-i.snd-1)]=0;
			}
			auto ul=max(st.query(0,co),st.query(co+1,n));
			if(ul>=a[-i.snd-1].fst)res[(b?n+i.snd:-i.snd-1)]=0;
			if(ca[co]==1)qc--;
			ca[co]--;
			st.upd(co,i.fst-1);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a.clear(); a.resize(n);
		c.clear(); c.resize(n);
		fore(i,0,n){
			ll l,r,co; cin>>l>>r>>co;
			l--; r--; co--;
			a[i]={l,r};
			c[i]=co;
		}
		res.clear();
		res.resize(n,2e9);
		solvepp();
		rever();
		solvepp();
		rever();
		solvesg();
		rever();
		solvesg();
		rever();
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}