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

const int MAXN=300005;
ll n,q; 
ll a[MAXN];

struct Node{
	ll maxs[2][2];
};

Node oper(Node a, Node b){
	Node res;
	//cout<<"Empieza\n";
	fore(i,0,2){
		fore(j,0,2){
			res.maxs[i][j]=max(a.maxs[i][0]+b.maxs[1][j],a.maxs[i][1]+b.maxs[0][j]);
			//cout<<a.maxs[i][j]<<" "<<b.maxs[i][j]<<" "<<res.maxs[i][j]<<"\n";
		}
	}
	//cout<<"Termina\n";
	return res;
}

/*----------------CLASSIC SEGMENT TREE----------------*/
const Node NEUT={{0,0,0,0}};
struct STree { // [cerrado-abierto)
    vector<Node> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, Node v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    Node query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, Node v){upd(1,0,n,p,v);}
    Node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

STree st(MAXN);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)st.upd(i,{a[i],0,0,-a[i]});
		auto res=st.query(0,n);
		cout<<max(res.maxs[0][0],res.maxs[0][1])<<"\n";
		while(q--){
			ll l,r; cin>>l>>r; l--; r--;
			swap(a[l],a[r]);
			st.upd(l,{a[l],0,0,-a[l]});
			st.upd(r,{a[r],0,0,-a[r]});
			res=st.query(0,n);
			cout<<max(res.maxs[0][0],res.maxs[0][1])<<"\n";
		}
	}
	
	return 0;
}