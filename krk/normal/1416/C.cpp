#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 30;
const int Maxn = 300005;

int n;
vector <int> A;
ll my01[Maxb], my10[Maxb];
ll res, mask;

void Solve(int b, const vector <int> &V)
{
    if (b < 0 || V.empty()) return;
    vector <int> ones, zers;
    for (int i = 0; i < V.size(); i++)
        if (V[i] & 1 << b) {
            my01[b] += int(zers.size());
            ones.push_back(V[i]);
        } else {
            my10[b] += int(ones.size());
            zers.push_back(V[i]);
        }
    Solve(b - 1, ones);
    Solve(b - 1, zers);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        A.push_back(a);
    }
    Solve(Maxb - 1, A);
    for (int i = Maxb - 1; i >= 0; i--) {
        res += min(my01[i], my10[i]);
        if (my10[i] > my01[i]) mask |= 1 << i;
    }
    printf("%I64d %I64d\n", res, mask);
    return 0;
}