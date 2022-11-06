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

string s; 

string anto="ANTO";

#define oper(a,b) a+b
#define NEUT 0
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

STree st(100005);

vector<ll> oc[4];

ll solve(string t){
	fore(i,0,SZ(t)){
		st.upd(i,1);
	}
	fore(i,0,4)oc[i].clear();
	fore(i,0,SZ(s)){
		fore(j,0,4){
			if(s[i]==anto[j]){
				oc[j].pb(i);
			}
		}
	}
	fore(i,0,4)reverse(ALL(oc[i]));
	ll res=0;
	for(auto i:t){
		ll pos=-1;
		fore(j,0,4){
			if(anto[j]==i)pos=j;
		}
		assert(SZ(oc[pos]));
		auto b=oc[pos].back();
		oc[pos].pop_back();
		res+=st.query(0,b);
		st.upd(b,0);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		ll c[4]={0,0,0,0};
		for(auto i:s){
			fore(j,0,4){
				if(i==anto[j])c[j]++;
			}
		}
		ll p[4]={0,1,2,3};
		pair<ll,string> res={-1,""};
		do{
			string t;
			fore(i,0,4){
				fore(j,0,c[p[i]]){
					t+=anto[p[i]];
				}
			}
			res=max(res,{solve(t),t});
		}while(next_permutation(p,p+4));
		cout<<res.snd<<"\n";
	}
	
	return 0;
}