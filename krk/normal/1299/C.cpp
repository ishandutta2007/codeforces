#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 1000005;

int n;
vector <ill> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        seq.push_back(ill(1, ll(a)));
        while (seq.size() >= 2 &&
               ld(seq[int(seq.size()) - 2].second) / seq[int(seq.size()) - 2].first >
               ld(seq.back().second) / seq.back().first) {
            int cnt = seq[int(seq.size()) - 2].first + seq.back().first;
            ll sum = seq[int(seq.size()) - 2].second + seq.back().second;
            seq.pop_back();
            seq.back() = ill(cnt, sum);
        }
    }
    for (int i = 0; i < seq.size(); i++) {
        ld val = ld(seq[i].second) / seq[i].first;
        while (seq[i].first--)
            printf("%.9f\n", double(val));
    }
    return 0;
}