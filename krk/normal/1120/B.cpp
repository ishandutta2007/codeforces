#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int lim = 100000;

int n;
string A, B;
vector <ii> res;
int my[Maxn];
set <int> S;
ll ans;

void Move(int ind, int val)
{
    res.push_back(ii(ind, val));
    my[ind] -= val;
    A[ind] += val; A[ind + 1] += val;
    if (ind > 0) S.insert(ind - 1);
    S.insert(ind);
    if (ind + 2 < n) S.insert(ind + 1);
}

int main()
{
    cin >> n;
    cin >> A;
    cin >> B;
    ll delt = int(B[0] - '0') - int(A[0] - '0');
    for (int i = 0; i + 1 < n; i++) {
        ans += abs(delt);
        my[i] = delt;
        delt = -delt + int(B[i + 1] - '0') - int(A[i + 1] - '0');
    }
    if (delt != 0) { printf("-1\n"); return 0; }
    cout << ans << endl;
    for (int i = 0; i + 1 < n; i++)
        S.insert(i);
    while (!S.empty() && res.size() < lim) {
        set <int>::iterator it = S.begin();
        int v = *it; S.erase(it);
        if (my[v] < 0 && (A[v] > '1' || v > 0 && A[v] > '0') && A[v + 1] > '0')
            Move(v, -1);
        else if (my[v] > 0 && A[v] < '9' && A[v + 1] < '9')
            Move(v, 1);
    }
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first + 1, res[i].second);
    return 0;
}