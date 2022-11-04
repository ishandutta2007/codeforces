#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, p[MX];
map<int, int> fin;

void main_() {
	cin >> n;
	
	fin.clear();
	forn (i, n) {
		cin >> p[i];
		fin[p[i]] = i;
	}
	
	set<int> st;
	int suf = n - 1;
	while (0 < suf && p[suf - 1] <= p[suf])
		suf--;
	
	int ind = 0;
	while (ind < suf) {
		if (st.count(p[ind])) {
		} else {
			suf = max(suf, fin[p[ind]]);
			st.insert(p[ind]);
		}
		
		ind++;
	}
	
	cout << st.size() << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}