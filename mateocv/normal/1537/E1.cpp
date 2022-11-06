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
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	string res;
	fore(i,1,n+1){
		string t;
		fore(j,0,i)t+=s[j];
		string va(k,'.');
		fore(j,0,k){
			va[j]=t[j%i];
		}
		if(i==1)res=va;
		else res=min(res,va);
	}
	cout<<res<<"\n";
	
	return 0;
}