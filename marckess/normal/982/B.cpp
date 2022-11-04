#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 200005;
int n, w;
string s;

set<ii> in, out;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> w;
    	in.emplace(w, i);
    }
    cin >> s;

    for (int c : s) {
    	if (c == '0') {
    		cout << in.begin()->se << " ";
    		out.insert(*in.begin());
    		in.erase(in.begin());
    	} else {
    		auto it = out.end();
    		it--;
    		cout << it->se << " ";
    		out.erase(it);
    	}
    }
    cout << endl;

    return 0;
}