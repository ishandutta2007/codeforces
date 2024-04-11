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
// MAXN: max number of nodes or 2 * max number of variables (2SAT)
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
	fore(i,0,nvar)idx[i]=0,idx[neg(i)]=0;qidx=0;
	fore(i,0,nvar)cmp[i]=-1,cmp[neg(i)]=-1;qcmp=0;
	fore(i,0,nvar)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll x; cin>>x;
		ll br=0;
		fore(i,0,SZ(s)){
			if(i-x<0&&i+x>=SZ(s)&&s[i]=='1'){
				br++; break;
			}
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,SZ(s)){
			g[i].clear();
			g[neg(i)].clear();
		}
		fore(i,0,SZ(s)){
			if(s[i]=='1'){
				if(i-x>=0&&i+x<SZ(s)){
					addor(i-x,i+x);
				}else if(i-x<0&&i+x<SZ(s)){
					addor(i+x,i+x);
				}else if(i-x>=0&&i+x>=SZ(s)){
					addor(i-x,i-x);
				}else if(i-x<0&&i+x>=SZ(s)){
					assert(0);
				}
			}else{
				if(i-x>=0&&i+x<SZ(s)){
					addor(neg(i-x),neg(i-x));
					addor(neg(i+x),neg(i+x));
				}else if(i-x<0&&i+x<SZ(s)){
					addor(neg(i+x),neg(i+x));
				}else if(i-x>=0&&i+x>=SZ(s)){
					addor(neg(i-x),neg(i-x));
				}
			}
		}
		auto res=satisf(SZ(s));
		if(res){
			fore(i,0,SZ(s)){
				if(truth[cmp[i]])cout<<'1';
				else cout<<'0';
			}
			cout<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
	
	return 0;
}