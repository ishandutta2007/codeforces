#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

const int max_n = 400111, inf = 1000111222;

int m[max_n];
int m1[max_n];
int n,M;
int MID = 200000;

int summ[max_n];


ll get(int mid) {
    memset(summ, 0, sizeof(summ));
    for (int i = 0; i < n; ++i) {
        if (m[i] >= mid) {
            m1[i] = 1;
        } else {
            m1[i] = -1;
        }
    }
    ll sum = 0;
    ll ans = 0;
    ll d = 0;
    summ[MID] = 1;
    for (int i = 0; i < n; ++i) {
        sum += m1[i];
        if (m1[i] == 1) {
            d += summ[MID + sum - 1];
        } else {
            d -= summ[MID + sum];
        }
        ans += d;
        summ[MID + sum]++;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    cout << (get(M) - get(M + 1));

    return 0;
}