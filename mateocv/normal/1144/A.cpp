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

ll dist(string &s){
	fore(i,0,SZ(s)){
		fore(j,i+1,SZ(s)){
			if(s[i]==s[j])return 0;
		}
	}
	return 1;
}

void solve(string &s){
	sort(ALL(s));
	if(0+s[SZ(s)-1]-s[0]==SZ(s)-1&&dist(s)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}

int main(){FIN;
	ll n; cin>>n;
	while(n--){
		string s; cin>>s;
		solve(s);
	}
	
	return 0;
}