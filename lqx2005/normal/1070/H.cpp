#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, q;
map < string, int > mp;
map < string, string > what;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		set < string > st;
		string x;
		cin >> x;
		int l = sz(x);
		L(i, 0, l - 1) {
			string p;
			L(j, i, l - 1) p.push_back(x[j]), st.insert (p);
		}
		for (auto p : st) 
			mp[p] += 1, what[p] = x;
	}
	cin >> q;
	while (q--) {
		string x;
		cin >> x;
		cout << mp[x] << ' ';
		if(what.count (x)) cout << what[x] << '\n';
		else cout << "-\n";
	}
	return 0;
}