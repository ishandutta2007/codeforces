/**
* Sources: various
*/

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
template<typename T>
ostream& operator<< (ostream& out, const pair<T, T>& v) {
    out << "{" << v.first << ", " << v.second << "}";
    return out;
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "]";
    return out;
}

template<typename T>
ostream& operator<< (ostream& out, const set<T>& v) {
    out << "[";
    auto pen = v.end();
    pen--;
    for (auto it = v.begin(); it != v.end(); it++){
		out << *it;
		if (it != pen){
			out << ", ";
		}
	}
	out << "]";
    return out;
}

template<typename T>
ostream& operator<< (ostream& out, const Tree<T>& v) {
    out << "[";
    auto pen = v.end();
    pen--;
    for (auto it = v.begin(); it != v.end(); it++){
		out << *it;
		if (it != pen){
			out << ", ";
		}
	}
	out << "]";
    return out;
}

ll pref[100001];
ll suff[100001];
ll A[100001];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N; int p; cin >> N >> p;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	pref[0] = 0;
	for (int i = 0; i < N; i++){
		pref[i + 1] = pref[i] + A[i]; 
		pref[i + 1] %= p;
	}
	suff[0] = 0;
	for (int i = 0; i < N; i++){
		suff[i + 1] = suff[i] + A[N - i - 1];
		suff[i + 1] %= p;
	}
	int mx = 0;
	for (int i = 1; i < N; i++){
		if (pref[i] + suff[N - i] > mx){
			mx = pref[i] + suff[N - i];
		}
	}
	cout << mx << endl;
}

// read!read!read!read!read!read!read!
// ll vs. int!