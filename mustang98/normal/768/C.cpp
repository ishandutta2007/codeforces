#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_p = 2111;
int m[max_n];
int cnt[max_p], cnt1[max_p];

int main()
{
    int n, k, x, a;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 0; i < k; ++i) {
        int numb = 0, cntu, cntx;
        for (int j = 0; j < max_p; ++j) {
            cntu = cntx = cnt[j] / 2;
            if (cnt[j] % 2 == 1) {
                if (numb % 2 == 0) cntx++;
                else cntu++;
            }
            cnt1[j] += cntu;
            cnt1[j ^ x] += cntx;
            numb += cnt[j];
        }
        for (int j = 0; j < max_p; ++j) {
            cnt[j] = cnt1[j];
            cnt1[j] = 0;
        }
    }
    int maxa = -1, mina = 2000;
    for (int i = 0; i < max_p; ++i) {
        if (cnt[i] == 0) continue;
        mina = min(mina, i);
        maxa = max(maxa, i);
    }
    cout << maxa << ' ' << mina;
    return 0;
}