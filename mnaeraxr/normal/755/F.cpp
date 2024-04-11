#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;
const int T = 100;

int P[maxn];


int solve(vector<int> &sz, int k){
	bitset<1000001> ks;
	ks.set(0);

	sort(sz.begin(), sz.end());
	int p = (int)sz.size() - 1;

	while (p >= 0 && sz[p] > T)
		ks |= ks << sz[p--];


	map<int,int> freq;

	while (p >= 0)
		freq[ sz[p--] ]++;

	for (auto P : freq){
		vector<int> m(k + 1, oo);

		for (int i = 0; i <= k; ++i){
			if (ks.test(i)) m[i] = 0;
			else{
				if (i >= P.first && m[i - P.first] < P.second){
					ks.set(i);
					m[i] = m[i - P.first] + 1;
				}
			}
		}
	}

	return ks.test(k) ? k : k + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i){
        cin >> P[i];
        P[i]--;
    }

    vector<int> SZ;

    for (int i = 0; i < n; ++i){
        if (P[i] == -1) continue;

        int u = i, sz = 0;

        while (P[u] != -1){
            int v = P[u];
            P[u] = -1;
            sz++;
            u = v;
        }

        SZ.push_back(sz);
    }

    sort(SZ.begin(), SZ.end());
    int tot = (int)SZ.size();

    int M = 0;

    int t1 = 0, K = k;

    for (int i = 0; i < tot && K; ++i){
        int v = min(SZ[i] / 2, K);
        M += 2 * v;
        K -= v;
        if (SZ[i] & 1) t1++;
    }

    M += min(t1, K);


    int m = k == 0 ? 0 : solve(SZ, k);

    cout << m << " " << M << endl;

    return 0;
}