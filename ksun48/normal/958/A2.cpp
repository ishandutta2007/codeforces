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
typedef pair<ll, ll> pll;
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

ll modpow(ll b, ll p) {
	return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll base1 = 15235;
ll base2 = 71345;
ll base3 = 3511;
ll base4 = 31671;
ll invbase1;
ll invbase2;
ll invbase3;
ll invbase4; 

char A[2005][205];
char B[205][2005];
ll prefixA1[2005][205];
ll prefixB1[205][2005];

ll prefixA2[2005][205];
ll prefixB2[205][2005];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	invbase1 = modpow(base1, MOD - 2);
	invbase2 = modpow(base2, MOD - 2);
	invbase3 = modpow(base3, MOD - 2);
	invbase4 = modpow(base4, MOD - 2);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			cin >> B[i][j];
		}
	}
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= M; j++){
			if (i == 0 || j == 0){
				prefixA1[i][j] = 0LL;
			}
			else{
				prefixA1[i][j] = prefixA1[i][j-1] + prefixA1[i-1][j] - prefixA1[i-1][j-1] + (((A[i-1][j-1] - 'a')*modpow(base1, i - 1)%MOD)*modpow(base2, j - 1))%MOD;
				prefixA1[i][j] %= MOD;
				prefixA1[i][j] += MOD;
				prefixA1[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i <= M; i++){
		for (int j = 0; j <= N; j++){
			if (i == 0 || j == 0){
				prefixB1[i][j] = 0LL;
			}
			else{
				prefixB1[i][j] = prefixB1[i][j-1] + prefixB1[i-1][j] - prefixB1[i-1][j-1] + (((B[i-1][j-1] - 'a')*modpow(base1, i - 1)%MOD)*modpow(base2, j - 1))%MOD;
				prefixB1[i][j] %= MOD;
				prefixB1[i][j] += MOD;
				prefixB1[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= M; j++){
			if (i == 0 || j == 0){
				prefixA2[i][j] = 0LL;
			}
			else{
				prefixA2[i][j] = prefixA2[i][j-1] + prefixA2[i-1][j] - prefixA2[i-1][j-1] + (((A[i-1][j-1] - 'a')*modpow(base3, i - 1)%MOD)*modpow(base4, j - 1))%MOD;
				prefixA2[i][j] %= MOD;
				prefixA2[i][j] += MOD;
				prefixA2[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i <= M; i++){
		for (int j = 0; j <= N; j++){
			if (i == 0 || j == 0){
				prefixB2[i][j] = 0LL;
			}
			else{
				prefixB2[i][j] = prefixB2[i][j-1] + prefixB2[i-1][j] - prefixB2[i-1][j-1] + (((B[i-1][j-1] - 'a')*modpow(base3, i - 1)%MOD)*modpow(base4, j - 1))%MOD;
				prefixB2[i][j] %= MOD;
				prefixB2[i][j] += MOD;
				prefixB2[i][j] %= MOD;
			}
		}
	}
	
	vector<pll> v1;
	vector<pll> v2;
	for (int i = 0; i <= N - M; i++){
		v1.push_back(make_pair((modpow(invbase1, i)*((prefixA1[i + M][M] - prefixA1[i][M] + MOD)%MOD))%MOD, (modpow(invbase3, i)*((prefixA2[i + M][M] - prefixA2[i][M] + MOD)%MOD))%MOD));
	}
	for (int i = 0; i <= N - M; i++){
		v2.push_back(make_pair((modpow(invbase2, i)*((prefixB1[M][i + M] - prefixB1[M][i] + MOD)%MOD))%MOD, (modpow(invbase4, i)*((prefixB2[M][i + M] - prefixB2[M][i] + MOD)%MOD))%MOD));
	}
	for (int i = 0; i <= N - M; i++){
		for (int j = 0; j <= N - M; j++){
			if (v1[i] == v2[j]){
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
		}
	}
	
}

// read!read!read!read!read!read!read!
// ll vs. int!