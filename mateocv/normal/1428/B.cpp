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

const int MAXN=600005;

bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	fore(i,0,2*n)idx[i]=0,qidx=0;
	fore(i,0,2*n)cmp[i]=-1,qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

map<ll,ll> mp;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		string s; cin>>s;
		fore(i,0,n)g[i].clear();
		fore(i,0,n){
			if(s[i]=='-'){
				g[i].pb((i+1)%n);
				g[(i+1)%n].pb(i);
			}
			if(s[i]=='>'){
				g[i].pb((i+1)%n);
			}
			if(s[i]=='<'){
				g[(i+1)%n].pb(i);
			}
		}
		mp.clear();
		scc();
		fore(i,0,n){
			mp[cmp[i]]++;
		}
		//fore(i,0,n)cout<<idx[i]<<" "; cout<<"\n";
		//fore(i,0,n)cout<<cmp[i]<<" "; cout<<"\n";
		ll res=0;
		for(auto i:mp){
			if(i.snd!=1)res+=i.snd;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}