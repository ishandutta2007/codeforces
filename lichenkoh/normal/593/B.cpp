#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define UNDEF -1

ll binsearch(vector<ll>& A, ll key, ll imin, ll imax)
{
    while (imin <= imax)
    {
      	ll imid = imin + ((imax - imin) / 2);
      	if(A[imid] == key)
            return imid; 
        else if (A[imid] < key)
            imin = imid + 1;
      	else         
            imax = imid - 1;
    }
    assert(false);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	ll x1,x2; cin >> x1; cin >> x2;
	ll *b = new ll[n];
	ll *k = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> k[i]; cin >> b[i];
	}
	set<ll> s;
	for (ll i = 0; i < n; i++) {
		ll y = k[i]*x1 + b[i];
		s.insert(y);
		y = k[i]*x2 + b[i];
		s.insert(y);
	}
	ll m = s.size();
	vector<ll> a;
	for (auto &y: s) {
		a.PB(y);
	}
	vector<ll> *left = new vector<ll>[m];
	vector<ll> *right = new vector<ll>[m];
	for (ll i = 0; i < n; i++) {
		ll y1 = k[i]*x1 + b[i];
		ll p1 = binsearch(a, y1, 0, m);
		left[p1].PB(k[i]);
		ll y2 = k[i]*x2 + b[i];
		ll p2 = binsearch(a, y2, 0, m);
		right[p2].PB(k[i]);
	}
	for (ll p = 0; p < m; p++) {
		sort(left[p].begin(), left[p].end());
		sort(right[p].begin(), right[p].end());
	}
	ll *leftlow = new ll[m];
	ll *rightlow = new ll[m];
	leftlow[0] = 0;
	rightlow[0] = 0;
	for (ll p = 1; p < m; p++) {
		leftlow[p] = leftlow[p-1] + left[p-1].size();
		rightlow[p] = rightlow[p-1] + right[p-1].size();
	}
	bool cross = false;
	for (ll i = 0; i < n; i++) {
		ll y1 = k[i]*x1 + b[i];
		ll p1 = binsearch(a, y1, 0, m);
		ll leftbelow = leftlow[p1];
		ll y2 = k[i]*x2 + b[i];
		ll p2 = binsearch(a, y2, 0, m);
		ll rightbelow = rightlow[p2];
		ll leftlessslope = binsearch(left[p1], k[i], 0, left[p1].size());
		ll rightmoreslope = right[p2].size() - 1 - binsearch(right[p2], k[i], 0, right[p2].size());
		if (leftbelow + leftlessslope != rightbelow + rightmoreslope) {
			cross = true; break;
		}
	}
	if (cross) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}