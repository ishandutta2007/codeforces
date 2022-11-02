#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 300100;
const int block = 500;
const ll inf = 2e18;

int n;
int qt[maxn], qa[maxn], qb[maxn];
piii qry[maxn]; int qsze;
bool in[maxn];
pii add[maxn], inter[maxn];
bool rem[maxn];
int adds;

pii q3[maxn]; int q3s;
ll ans[maxn];

pii line[maxn]; int ls;

bool reml(pii p3) {
    if (ls < 2) return 0;
    pii p1 = line[ls - 2], p2 = line[ls - 1];
    return ll(p1.B - p3.B) * (p3.A - p2.A) >= ll(p2.B - p3.B) * (p3.A - p1.A);
}

ll val(pii p, int x) {
    return ll(p.A) * x + p.B;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> qt[i];
        if (qt[i] == 1) {
            cin >> qa[i] >> qb[i];
            qry[qsze++] = piii(pii(qa[i], qb[i]), i);
        } else {
            cin >> qa[i];
            if (qt[i] == 2) qa[i]--;
        }
    }

    sort(qry, qry + qsze);

    for (int i = 0; i < n; i++) ans[i] = -inf;

    for (int i = 0; i < n; i++) {
        if (i % block == 0) {
            for (int j = 0; j < adds; j++)
                if (inter[j].B == n)
                    in[inter[j].A] = 1;

            adds = q3s = ls = 0;
            int ie = (i / block + 1) * block;
            for (int j = i; j < ie; j++) {
                if (qt[j] == 2) {
                    int k = qa[j];
                    in[k] = 0;
                    rem[k] = 1;
                    add[adds] = pii(qa[k], qb[k]);
                    inter[adds] = pii(k, j);
                    adds++;
                } else if (qt[j] == 3) {
                    q3[q3s++] = pii(qa[j], j);
                }
            }

            for (int j = i; j < ie; j++)
                if (qt[j] == 1) {
                    if (!rem[j]) {
                        add[adds] = pii(qa[j], qb[j]);
                        inter[adds] = pii(j, n);
                        adds++;
                    }
                }
/*
            if (i == 4) {
                for (int j = 0; j < n; j++)
                    cout << in[j] << ' ';
                cout << endl;
            }
*/
            for (int j = 0; j < qsze; j++) {
                if (!in[qry[j].B]) continue;
                pii p = qry[j].A;
                while (reml(p)) ls--;
                line[ls++] = p;
            }

            //if (i == 4) cout << line[0].A << ' ' << line[0].B << endl;

            sort(q3, q3 + q3s);
            int p = 0;
            for (int j = 0; j < q3s; j++) {
                int x = q3[j].A;
                while (p + 1 < ls && val(line[p], x) <= val(line[p + 1], x)) p++;
                if (ls) ans[q3[j].B] = val(line[p], x);
                /*
                if (q3[j].B == 4) {
                    cout << p << ' ' << ls << endl;
                    cout << line[p].A << ' ' << line[p].B << endl;
                    cout << line[0].A << ' ' << line[0].B << endl;
                }
                */
            }

            for (int j = i; j < ie; j++)
                if (qt[j] == 3) {
                    int x = qa[j];

                    for (int k = 0; k < adds; k++)
                        if (inter[k].A <= j && j < inter[k].B)
                            ans[j] = max(ans[j], val(add[k], x));
                }
        }
    }

    for (int i = 0; i < n; i++)
        if (qt[i] == 3) {
            if (ans[i] == -inf) cout << "EMPTY SET\n";
            else cout << ans[i] << '\n';
        }
}