#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 30;

int n;
vector <int> seq;

int Solve(int lvl, const vector <int> &V)
{
    if (lvl < 0 || V.size() <= 2) return 0;
    vector <int> A, B;
    for (int i = 0; i < V.size(); i++)
        if (V[i] & 1 << lvl) A.push_back(V[i]);
        else B.push_back(V[i]);
    int res = min(Solve(lvl - 1, A) + max(0, int(B.size()) - 1),
                  Solve(lvl - 1, B) + max(0, int(A.size()) - 1));
    return res;
}

int main()
{
    scanf("%d", &n);
    seq.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &seq[i]);
    cout << Solve(Maxb - 1, seq) << endl;
    return 0;
}