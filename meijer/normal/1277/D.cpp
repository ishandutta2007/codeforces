#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
int t, n;
map<string, int> words;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--) {
		words.clear();
		cin>>n;
		int zo=0, oz=0;
		bool zz=0, oo=0;
		RE(i,n) {
			string s; cin>>s;
			words[s] = i+1;
			if(s[0]=='0' && s.back()=='0') zz=1;
			if(s[0]=='1' && s.back()=='1') oo=1;
			if(s[0]=='0' && s.back()=='1') zo++;
			if(s[0]=='1' && s.back()=='0') oz++;
		}
		if(oz == 0 && zo == 0) {
			if(zz && oo) {
				cout<<-1<<endl;
			} else {
				cout<<0<<endl<<endl;
			}
			continue;
		}
		vi ans;
		for(auto s:words) {
			string r = s.fi;
			reverse(r.begin(), r.end());
			if(words.count(r)) continue;
			if(r[0]=='0' && r.back()=='0') continue;
			if(r[0]=='1' && r.back()=='1') continue;
			if(zo+1 < oz) {
				if(r[0]=='0' && r.back()=='1') {
					ans.pb(s.se);
					zo++; oz--;
				}
			}
			if(oz+1 < zo) {
				if(r[0]=='1' && r.back()=='0') {
					ans.pb(s.se);
					oz++; zo--;
				}
			}
		}
		cout<<ans.size()<<endl;
		RE(i,ans.size()) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
	}
}