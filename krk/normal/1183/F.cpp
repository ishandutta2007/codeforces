#include <bits/stdc++.h>
using namespace std;

struct triple {
    int a, b, c;
    bool operator <(const triple &u) const {
        if (a != u.a) return a < u.a;
        if (b != u.b) return b < u.b;
        return c < u.c;
    }
};

typedef pair <int, triple> it;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int q;
int n;
vector <int> seq;

bool Check(int a, int b) { return seq[b] % seq[a]; }

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        seq.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            seq.push_back(a);
        }
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        int res = seq.back();
        if (seq.size() >= 2) {
            set <iii> S;
            S.insert(iii(-seq[int(seq.size()) - 2] - seq.back(), ii(int(seq.size()) - 2, int(seq.size()) - 1)));
            while (!S.empty() && -S.begin()->first > res) {
                ii p = S.begin()->second;
                int cand = -S.begin()->first; S.erase(S.begin());
                if (Check(p.first, p.second)) { res = cand; break; }
                if (p.first > 0)
                    S.insert(iii(-seq[p.first - 1] - seq[p.second], ii(p.first - 1, p.second)));
                if (p.second - 1 > p.first)
                    S.insert(iii(-seq[p.first] - seq[p.second - 1], ii(p.first, p.second - 1)));
            }
        }
        if (seq.size() >= 3) {
            set <it> S;
            S.insert(it(-seq[int(seq.size()) - 3] - seq[int(seq.size()) - 2] - seq.back(),
                         {int(seq.size()) - 3, int(seq.size()) - 2, int(seq.size()) - 1}));
            while (!S.empty() && -S.begin()->first > res) {
                triple t = S.begin()->second;
                int cand = -S.begin()->first; S.erase(S.begin());
                if (Check(t.a, t.b) && Check(t.a, t.c) && Check(t.b, t.c)) { res = cand; break; }
                if (t.a > 0)
                    S.insert(it(-seq[t.a - 1] - seq[t.b] - seq[t.c], {t.a - 1, t.b, t.c}));
                if (t.b - 1 > t.a)
                    S.insert(it(-seq[t.a] - seq[t.b - 1] - seq[t.c], {t.a, t.b - 1, t.c}));
                if (t.c - 1 > t.b)
                    S.insert(it(-seq[t.a] - seq[t.b] - seq[t.c - 1], {t.a, t.b, t.c - 1}));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}