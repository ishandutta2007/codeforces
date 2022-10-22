#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 300005;
const int Maxd = 25;

ld pw2[Maxd];
int n;
int a[Maxn];
vector <ii> seq;
set <int> S;
ld res;

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxd; i++)
        pw2[i] = 2.0l * pw2[i - 1];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq.push_back(ii(a[i], i));
    }
    sort(seq.rbegin(), seq.rend());
    S.insert(-1);
    S.insert(n);
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        set <int>::iterator it = S.insert(ind).first;
        int cnt = 0;
        set <int>::iterator lef = it;
        while (lef != S.begin() && cnt + 1 < Maxd) {
            cnt++;
            int rig1 = *lef;
            lef--;
            int lef1 = *lef;
            set <int>::iterator rig = it;
            int ncnt = cnt;
            while (*rig < n && ncnt < Maxd) {
                int lef2 = *rig;
                rig++;
                int rig2 = *rig;
                res += ld(rig1 - lef1) / ld(n) * ld(rig2 - lef2) / ld(n) * seq[i].first / pw2[ncnt];
                ncnt++;
            }
        }
    }
    cout << fixed << setprecision(16) << res << endl;
    return 0;
}