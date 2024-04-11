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
	ll n,m,k; cin>>n>>m>>k;
	string res;
	fore(i,0,n-1)res+="U";
	fore(i,0,m-1)res+="L";
	fore(i,0,n){
		fore(j,0,m-1){
			if(i%2==0){
				res+="R";
			}else res+="L";
		}
		if(i!=n-1)res+="D";
	}
	cout<<SZ(res)<<"\n";
	cout<<res;
	return 0;
}