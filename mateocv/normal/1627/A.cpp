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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,x,y; cin>>n>>m>>x>>y; x--; y--;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		ll cant=0,cantx=0,canty=0;
		fore(i,0,n){
			fore(j,0,m){
				cant+=(s[i][j]=='B');
				if(i==x)cantx+=(s[i][j]=='B');
				if(j==y)canty+=(s[i][j]=='B');
			}
		}
		if(!cant){
			cout<<"-1\n";
			continue;
		}
		if(s[x][y]=='B')cout<<"0\n";
		else if(cantx||canty)cout<<"1\n";
		else cout<<"2\n";
	}
	
	return 0;
}