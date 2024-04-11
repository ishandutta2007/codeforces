#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const int N = 1e5;
int ar[N + 5];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int s, b; cin >> s >> b;
	vector<ii> ls;
	for(int i = 0; i < s; ++i) cin >> ar[i];
	for(int i = 0; i < b; ++i){
		int a, b; cin >> a >> b;
		ls.pb(ii(a, b));
	}
	
	sort(ls.begin(), ls.end());
	for(int i = 1; i < ls.size(); ++i){
		ls[i].se += ls[i - 1].se;
	}
	
	for(int i = 0; i < s; ++i){
		if(i)cout << " ";
		int l = 0, r = ls.size();
		while(l < r){
			int m = (l + r) / 2;
			if(ls[m].fi > ar[i])r = m;
			else l = m + 1;
		}
		if(l == 0)cout << 0;
		else cout << ls[l - 1].se;
	}
	cout << endl;
}