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
 
ll elem(string s,string t){
    sort(ALL(s));
    sort(ALL(t));
    return s==t;
}

#define oper(a,b) a+b
#define NEUT 0
struct STree {
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
	ll q; cin>>q;
	while(q--){
	    ll n; cin>>n;
	    string s,t; cin>>s>>t;
	    if(!elem(s,t)){
	        cout<<"NO\n";
	    }else{
	        vector<ll> v[26][2];
            fore(i,0,SZ(s)){
                v[s[i]-'a'][0].pb(i);
                v[t[i]-'a'][1].pb(i);
            }
            fore(i,0,26){
                reverse(ALL(v[i][0]));
            }
            ll br=0;
            fore(i,0,26){
                if(SZ(v[i][0])>=2){
                    cout<<"YES\n"; br++; break;
                }
            }
            if(br)continue;
            STree st(n);
            fore(i,0,n)st.upd(i,1);
            ll tot=0;
            fore(i,0,SZ(t)){
                tot+=st.query(0,v[t[i]-'a'][0].back());
                st.upd(v[t[i]-'a'][0].back(),0);
                v[t[i]-'a'][0].pop_back();
            }
            /*fore(i,0,26){
                fore(j,0,SZ(v[i][0])){
                    tot+=abs(v[i][0][j]-v[i][1][j]);
                }
            }
            tot/=2;*/
            if(tot%2){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
	    }
	}
	
	return 0;
}