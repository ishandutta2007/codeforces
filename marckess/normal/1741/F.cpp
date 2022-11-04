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

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, l[MX], r[MX], c[MX], tot[MX], sc[MX], res[MX];
vvi seg, sbc[MX];

#define OPEN 0
#define CLOSE 1
ordered_set st;
void count (vvi &seg, int cn[]) {
	vvi events;
	for (auto &v : seg) {
		events.pb({v[0], OPEN, v.back()});
		events.pb({v[1], CLOSE, v.back()});
	}
	
	sort(all(events));
	
	st.clear();
	int unc = 0;
	
	for (vi &e : events) {
		if (e[1] == OPEN) {
			unc++;
		} else {
			unc--;
			st.insert({e[0], e.back()});
			
			cn[e.back()] = unc;
			cn[e.back()] += st.size() - st.order_of_key({l[e.back()], -1});
		}
	}
}

multiset<int> mst;
int find_closest (int x) {
	auto it = mst.lower_bound(x);
	int res = 2e9;
	
	if (it != mst.end()) {
		res = min(res, abs(x - *it));
	}
	
	if (it != mst.begin()) {
		it--;
		res = min(res, abs(x - *it));
	}
	
	return res;
}

void main_() {
	cin >> n;
	
	seg.clear();
	mst.clear();
	forr (i, 1, n)
		sbc[i].clear();
	
	forn (i, n) {
		cin >> l[i] >> r[i] >> c[i];
		
		seg.pb({l[i], r[i], c[i], i});
		sbc[c[i]].pb({l[i], r[i], c[i], i});
		
		mst.insert(l[i]);
		mst.insert(r[i]);
	}
	
	count(seg, tot);
	forr (i, 1, n)
		count(sbc[i], sc);
	
	forr (i, 1, n) {
		for (vi &s : sbc[i]) {
			mst.erase(mst.find(s[0]));
			mst.erase(mst.find(s[1]));
		}
		
		for (vi &s : sbc[i]) {
			int j = s.back();
			
			if (tot[j] > sc[j]) {
				res[j] = 0;
			} else {
				res[j] = min(find_closest(s[0]), find_closest(s[1]));
			}
		}
		
		for (vi &s : sbc[i]) {
			mst.insert(s[0]);
			mst.insert(s[1]);
		}
	}
	
	forn (i, n) 
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}