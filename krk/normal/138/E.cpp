#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxl = 26;
const int Maxm = 505;

char str[Maxn];
int slen;
int pnt[Maxn], st[Maxn];
vector <int> V[Maxl];
int k, L, R;
int qc[Maxm], ql[Maxm], qr[Maxm];
ll res;

void Add(int l, int r, int npnt, int delt)
{
    for (int i = l; i <= r; i++) {
        if (L <= st[i] && st[i] <= R) res += npnt - pnt[i];
        pnt[i] = npnt;
        st[i] += delt;
    }
}

int main()
{
    scanf("%s", str); slen = strlen(str);
    int nil = 0;
    scanf("%d %d %d", &k, &L, &R);
    for (int i = 0; i < k; i++) {
        char ch; scanf(" %c %d %d", &ch, &ql[i], &qr[i]);
        qc[i] = ch - 'a';
        nil += ql[i] == 0;
    }
    for (int i = 0; i < slen; i++) {
        pnt[i] = i; st[i] = nil;
    }
    for (int i = 0; i < slen; i++) {
        int ind = str[i] - 'a';
        V[ind].push_back(i);
        for (int j = 0; j < k; j++) if (qc[j] == ind) {
            if (ql[j] > 0 && ql[j] <= V[ind].size()) {
                int lef = ql[j] == V[ind].size()? 0: V[ind][int(V[ind].size()) - 1 - ql[j]] + 1;
                int rig = V[ind][int(V[ind].size()) - ql[j]];
                Add(lef, rig, i, 1);
            }
            if (qr[j] + 1 <= V[ind].size()) {
                int lef = qr[j] + 1 == V[ind].size()? 0: V[ind][int(V[ind].size()) - 2 - qr[j]] + 1;
                int rig = V[ind][int(V[ind].size()) - 1 - qr[j]];
                Add(lef, rig, i, -1);
            }
        }
    }
    for (int i = 0; i < slen; i++)
        if (L <= st[i] && st[i] <= R)
            res += slen - pnt[i];
    cout << res << endl;
    return 0;
}