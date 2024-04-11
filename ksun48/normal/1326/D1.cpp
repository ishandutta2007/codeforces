#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> manacher(const string& s) {
	int n = sz(s);
	vi p[2] = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	vector<int> pp;
	for(int i = 0; i <= n; i++){
		pp.push_back(p[0][i] * 2);
		if(i < n) pp.push_back(p[1][i] * 2 + 1);
	}
	return pp;
}

string get_best(string s){
	vector<int> longest = manacher(s);
	int n = (int)s.size();
	vector<int> best(n+1, 0);
	for(int i = 0; i <= n; i++){
		int st = (i - longest[i]) / 2;
		best[st] = max(best[st], i);
	}
	int best_found = 0;
	int best_i = 0;
	int z = 0;
	for(int i = 0; i + i <= n; i++){
		if(i > 0){
			int x = i-1;
			int y = n-1-x;
			if(s[x] != s[y]) break;
		}
		z = max(z, best[i]);
		if(z > best_found){
			best_found = z;
			best_i = i;
		}
	}
	string res;
	res += s.substr(0, best_i);
	res += s.substr(best_i, z - best_i - best_i);
	res += s.substr(n - best_i, best_i);
	return res;
}

void solve(){
	string s;
	cin >> s;
	string res1 = get_best(s);
	string t = s;
	reverse(t.begin(), t.end());
	string res2 = get_best(t);
	if(res1.size() < res2.size()) res1 = res2;
	cout << res1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}