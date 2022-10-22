#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;

vector <int> ev, odd;
int T;
int n, a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        ev.clear(); odd.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 2) odd.push_back(i);
            else ev.push_back(i);
        }
        if (abs(int(odd.size()) - int(ev.size())) > 1) {
            printf("-1\n");
            continue;
        }
        ll cand1 = Inf, cand2 = Inf;
        if (odd.size() >= ev.size()) {
            cand1 = 0;
            for (int i = 0; i < odd.size(); i++)
                cand1 += abs(odd[i] - (2 * i));
        }
        if (ev.size() >= odd.size()) {
            cand2 = 0;
            for (int i = 0; i < ev.size(); i++)
                cand2 += abs(ev[i] - 2 * i);
        }
        printf("%I64d\n", min(cand1, cand2));
    }
    return 0;
}