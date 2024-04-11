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

string mix(string &s, string &t){
	string res;
	fore(i,0,SZ(s)){
		if(s[i]==t[i])res.pb(s[i]);
		else res.pb('S'+'E'+'T'-s[i]-t[i]);
	}
	return res;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	string s[n];
	fore(i,0,n)cin>>s[i];
	set<string> st;
	fore(i,0,n)st.insert(s[i]);
	ll res=0;
	fore(i,0,n){
		fore(j,i+1,n){
			if(st.count(mix(s[i],s[j])))res++;
		}
	}
	cout<<res/3;
	return 0;
}