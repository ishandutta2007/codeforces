#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vector<char> res;
	ll tot1=(n-11)/2,tot2=tot1;
	fore(i,0,n){
		if(s[i]=='8'){
			if(tot2>0){
				tot2--;
			}else{
				res.pb(s[i]);
			}
		}else{
			if(tot1>0){
				tot1--;
			}else{
				res.pb(s[i]);
			}
		}
	}
	if(tot1>0){
		cout<<"YES"; return 0;
	}
	if(tot2>0){
		cout<<"NO"; return 0;
	}
	if(res[0]=='8'){
		cout<<"YES"; return 0;
	}
	cout<<"NO"; return 0;
	
	return 0;
}