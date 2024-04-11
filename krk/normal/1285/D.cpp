#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxb = 30;

int n;
vector <int> seq;

int Solve(const vector <int> &seq, int b)
{
    if (b < 0 || seq.empty()) return 0;
    vector <int> tmp[2];
    for (int i = 0; i < seq.size(); i++)
        tmp[bool(seq[i] & 1 << b)].push_back(seq[i]);
    int v1 = Solve(tmp[0], b - 1), v2 = Solve(tmp[1], b - 1);
    int res = 1 << Maxb;
    // pick 1
    if (tmp[0].empty()) res = min(res, v2);
    else res = min(res, ((1 << b) | v1));
    // pick 0
    if (tmp[1].empty()) return min(res, v1);
    else res = min(res, ((1 << b) | v2));
    return res;
}

int main()
{
    scanf("%d", &n);
    seq.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &seq[i]);
    cout << Solve(seq, Maxb - 1) << endl;
    return 0;
}