#include <bits/stdc++.h>
#define pb push_back
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
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	set<char>st;
	fore(i,0,n){
		st.insert(s[i]);
	}
	vector<char>v;
	for(auto i:st){
		v.pb(i);
	}
	map<char,char> m;
	m['.']=v[0];
	fore(i,0,SZ(v)-1){
		m[v[i]]=v[i+1];
	}
	if(k>n){
		cout<<s;
		fore(i,0,k-n){
			cout<<m['.'];
		}
		return 0;
	}
	for(int i=k-1;i>=0;i--){
		if(s[i]!=v.back()){
			s[i]=m[s[i]];
			fore(j,i+1,n)s[j]=v[0];
			fore(j,0,k)cout<<s[j];
			return 0;
		}
	}
	
	return 0;
}