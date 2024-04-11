#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxb = 61;

int n;
ll a[Maxn];
int bits[Maxn];
vector <ii> valsA[Maxb], valsB[Maxb];
int sumA[Maxb], sumB[Maxb];
vector <ii> A, B;
int cur;
ll res;

int Get(int x, int b, vector <ii> &V, vector <ii> vals[], int sum[])
{
    if (V.empty()) return 0;
    int ind = lower_bound(V.begin(), V.end(), ii(x + 1, 0)) - V.begin() - 1;
    int ind2 = lower_bound(vals[b].begin(), vals[b].end(), ii(V[ind].first, 0)) - vals[b].begin();
    int res = 0;
    if (ind2 < vals[b].size()) res += sum[b] - vals[b][ind2].second;
    if (bits[V[ind].second] == b) res -= (x - V[ind].first);
    return res;
}

int Get(int l, int r, int b, vector <ii> &V, vector <ii> vals[], int sum[])
{
    return Get(l, b, V, vals, sum) - Get(r, b, V, vals, sum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        bits[i] = __builtin_popcountll(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int st = i;
        while (!A.empty() && a[A.back().second] <= a[i]) {
            int b = bits[A.back().second];
            cur -= Get(A.back().first, st, b, B, valsB, sumB);
            sumA[b] -= (st - A.back().first);
            valsA[b].pop_back();
            st = A.back().first;
            A.pop_back();
        }
        A.push_back(ii(st, i));
        int b = bits[A.back().second];
        cur += Get(A.back().first, i, bits[A.back().second], B, valsB, sumB);
        valsA[b].push_back(ii(st, sumA[b]));
        sumA[b] += i - st;
        st = i;
        while (!B.empty() && a[B.back().second] >= a[i]) {
            int b = bits[B.back().second];
            cur -= Get(B.back().first, st, bits[B.back().second], A, valsA, sumA);
            sumB[b] -= (st - B.back().first);
            valsB[b].pop_back();
            st = B.back().first;
            B.pop_back();
        }
        B.push_back(ii(st, i));
        b = bits[B.back().second];
        cur += Get(B.back().first, i, bits[B.back().second], A, valsA, sumA);
        valsB[b].push_back(ii(st, sumB[b]));
        sumB[b] += i - st + 1;
        sumA[bits[A.back().second]]++;
        if (bits[A.back().second] == bits[B.back().second])
            cur++;
        res += cur;
    }
    cout << res << endl;
    return 0;
}