#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100001;

vector <int> pr;
int nprime[Maxn];
int dv[Maxn];
int n;
set <vector <int> > S;
vector <int> my[Maxn];
bool was[Maxn];
vector <int> seq;
ll res;

int gcd(int x, int y)
{
    int a = 0, b = 0;
    while (a < my[x].size() && b < my[y].size())
        if (my[x][a] < my[y][b]) a++;
        else if (my[x][a] > my[y][b]) b++;
        else return 2;
    return 1;
}

int main()
{
    for (int i = 2; i < Maxn; i++) {
        if (!nprime[i]) {
            pr.push_back(i);
            dv[i] = i;
        }
        for (int j = 0; j < pr.size() && pr[j] * i < Maxn; j++) {
            nprime[pr[j] * i] = true;
            dv[pr[j] * i] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        was[a] = true;
    }
    for (int i = Maxn - 1; i > 0; i--) if (was[i]) {
        int num = i;
        vector <int> tmp, all;
        while (num > 1) {
            int d = dv[num];
            tmp.push_back(d);
            int tot = 1;
            while (dv[num] == d) {
                num /= d;
                tot *= d;
            }
            all.push_back(tot);
        }
        for (int j = 0; j < all.size(); j++)
            was[i / all[j]] = true;
        my[i] = tmp;
        if (S.find(tmp) == S.end()) S.insert(tmp);
        else was[i] = false;
    }
    for (int i = 1; i < Maxn; i++) if (was[i])
        seq.push_back(i);
    for (int i = int(seq.size()) - 1; i > 0; i--)
        if (ll(seq[i]) * seq[i - 1] <= res) break;
        else {
            int j = i - 1;
            while (j >= 0 && ll(seq[i]) * seq[j] > res)
                if (gcd(seq[i], seq[j]) == 1) { res = ll(seq[i]) * seq[j]; break; }
                else j--;
        }
    cout << res << endl;
    return 0;
}