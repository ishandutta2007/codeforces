#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

int main() {FIN;
	ll n,m; cin>>n>>m;
	string s[n];
	fore(i,0,n)cin>>s[i];
	ll a[m];
	set<ll>st;
	fore(i,0,m)cin>>a[i],a[i]--,st.insert(a[i]);
	fore(i,0,m){
		fore(j,i+1,m){
			if(SZ(s[a[i]])!=SZ(s[a[j]])){
				cout<<"No"; return 0;
			}
		}
	}
	string res=s[a[0]];
	fore(p,0,SZ(s[a[0]])){
		fore(i,0,m){
			fore(j,i+1,m){
				if(s[a[i]][p]!=s[a[j]][p]){
					res[p]='?';
				}
			}
		}
	}
	fore(i,0,n){
		if(SZ(res)==SZ(s[i])){
			ll tot=0;
			fore(p,0,SZ(res)){
				if(res[p]=='?'||res[p]==s[i][p])tot++;
			}
			if(tot==SZ(res)){
				if(!st.count(i)){
					cout<<"No"; return 0;
				}
			}else{
				if(st.count(i)){
					cout<<"No"; return 0;
				}
			}
		}else{
			if(st.count(i)){
					cout<<"No"; return 0;
				}
		}
	}
	cout<<"Yes\n";
	cout<<res;
	
}