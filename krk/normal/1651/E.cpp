#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n;

struct pos {
    int la, lb, lc, ld;
    int ra, rb, rc, rd;
    bool wrong;
    void Create(int a, int b) {
        if (a > b) swap(a, b);
        la = 0;
        lb = lc = a;
        ld = n + 1;
        ra = n;
        rb = rc = b;
        rd = 2 * n + 1;
        wrong = false;
    }
    void enterGood(int v) {
        if (v <= n) {
            lb = min(lb, v);
            lc = max(lc, v);
        } else {
            rb = min(rb, v);
            rc = max(rc, v);
        }
    }
    void enterBad(int v)
    {
        if (v <= n)
            if (v < lb) la = max(la, v);
            else if (v > lc) ld = min(ld, v);
            else wrong = true;
        else if (v < rb) ra = max(ra, v);
             else if (v > rc) rd = min(rd, v);
             else wrong = true;
    }
    bool Valid() {
        return !wrong && la < lb && lc < ld && ra < rb && rc < rd;
    }
    ll Ways() { return Valid()? ll(lb - la) * (ld - lc) * (rb - ra) * (rd - rc): 0ll; }
};

vector <int> neigh[Maxn];
bool tk[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        vector <int> seq;
        int v = i, par = -1;
        while (!tk[v]) {
            seq.push_back(v);
            tk[v] = true;
            int ind = 0;
            if (neigh[v][ind] == par) ind++;
            par = v; v = neigh[v][ind];
        }
        pos p;
        p.Create(seq[0], seq.back());
        for (int i = 0; i < seq.size(); i++)
            p.enterGood(seq[i]);
        res += ll(seq.size()) / 2 * p.Ways();
        for (int i = 0; i < seq.size(); i++) {
            pos cur;
            int prv = (i - 1 + int(seq.size())) % int(seq.size());
            int ni = (i + 1) % int(seq.size());
            cur.Create(seq[i], seq[ni]);
            cur.enterBad(seq[prv]);
            for (int j = 1; j + 1 < seq.size() && cur.Valid(); j++) {
                pos cp = cur;
                int nxt = (i + j + 1) % int(seq.size());
                cp.enterBad(seq[nxt]);
                res += ll(j + 1) / 2 * cp.Ways();
                cur.enterGood(seq[nxt]);
            }
        }
    }
    cout << res << endl;
    return 0;
}