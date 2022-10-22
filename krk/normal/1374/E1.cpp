#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n, k;
vector <ii> A, B, C;
ll res = Inf;

void Prepare(vector <ii> &V)
{
    sort(V.begin(), V.end());
    for (int i = 1; i < V.size(); i++)
        V[i].second = V[i - 1].second + V[i].first;
}

int main()
{
    scanf("%d %d", &n, &k);
    A.push_back(ii(0, 0));
    B.push_back(ii(0, 0));
    C.push_back(ii(0, 0));
    for (int i = 0; i < n; i++) {
        int t, a, b; scanf("%d %d %d", &t, &a, &b);
        if (a && !b) A.push_back(ii(t, 0));
        if (b && !a) B.push_back(ii(t, 0));
        if (a && b) C.push_back(ii(t, 0));
    }
    Prepare(A);
    Prepare(B);
    Prepare(C);
    for (int i = 0; i < C.size(); i++) if (i <= k && k - i < A.size() && k - i < B.size()) {
        res = min(res, ll(C[i].second) + A[k - i].second + B[k - i].second);
        //cout << i << " " << res << endl; 
    }
    printf("%I64d\n", res < Inf? res: -1ll);
    return 0;
}