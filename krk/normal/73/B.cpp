#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

struct racer {
       string s;
       int a;
       racer(const string &ss = "", int aa = 0) { s = ss; a = aa; }
       bool operator <(const racer &r) const {
            if (a != r.a) return a < r.a;
            return s > r.s;
       }
};

int n, m;
vector <racer> R;
int p[Maxn];
racer V;

int Highest()
{
    int lR = 0, rR = R.size() - 1;
    int res = 1;
    for (int i = n - 2; i >= 0; i--)
        if (racer(R[lR].s, R[lR].a + p[i]) < racer(V.s, V.a + p[n - 1])) lR++;
        else { rR--; res++; }
    return res;
}

int Lowest()
{
    int lR = 0, rR = R.size() - 1;
    int res = n;
    for (int i = 1; i < n; i++)
        if (racer(V.s, V.a + p[0]) < racer(R[rR].s, R[rR].a + p[i])) rR--;
        else { lR++; res--; }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n; R.resize(n);
    for (int i = 0; i < n; i++) cin >> R[i].s >> R[i].a;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> p[i];
    cin >> V.s;
    int torem = 0;
    while (R[torem].s != V.s) torem++;
    V.a = R[torem].a;
    R.erase(R.begin() + torem);
    sort(R.begin(), R.end());
    sort(p, p + n);
    cout << Highest() << " " << Lowest() << endl;
    return 0;
}