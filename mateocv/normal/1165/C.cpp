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
	vector<char> v;
	fore(i,0,n)v.pb(s[i]);
	ll res=0;
	vector<char> t;
	while(SZ(v)){
		if(res%2==0){t.pb(v.back());v.pop_back();res++;}
		else if(v.back()!=t[SZ(t)-1]){
			t.pb(v.back()); v.pop_back(); res++;
		}else {v.pop_back();}
	}
	if(SZ(t)&1)t.pop_back(),res--;
	cout<<n-res<<"\n";
	reverse(ALL(t));
	for(auto i:t)cout<<i;
	
	return 0;
}