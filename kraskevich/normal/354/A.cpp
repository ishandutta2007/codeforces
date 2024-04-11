#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;

long long n, l, r, ql, qr;

long long try1(vector<long long> v)
{
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = v[i];
        sum[i + 1] += sum[i];
    }
    long long res = sum[n] * l + ql * (n - 1);
    long long cur = 0;
    bool wasl = false;
    long long ll = 0;
    long long rr = n - 1;
    while (ll <= rr)
    {
        if (wasl)
        {
            res = min(res, cur + (rr - ll + 1) * ql + l * (sum[rr + 1] - sum[ll]));
            wasl = false;
            cur += r * v[rr];
            rr--;
        }
        else
        {
            res = min(res, cur + (rr - ll + 1) * qr + r * (sum[rr + 1] - sum[ll]));
            wasl = true;
            cur += l * v[ll];
            ll++;
        }
    }
    res = min(res, cur);
    return res;
}

long long try2(vector<long long> v)
{
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = v[i];
        sum[i + 1] += sum[i];
    }
    long long res = sum[n] * r + qr * (n - 1);
    long long cur = 0;
    bool wasl = true;
    long long ll = 0;
    long long rr = n - 1;
    while (ll <= rr)
    {
        if (wasl)
        {
            res = min(res, cur + (rr - ll + 1) * ql + l * (sum[rr + 1] - sum[ll]));
            wasl = false;
            cur += r * v[rr];
            rr--;
        }
        else
        {
            res = min(res, cur + (rr - ll + 1) * qr + r * (sum[rr + 1] - sum[ll]));
            wasl = true;
            cur += l * v[ll];
            ll++;
        }
    }
    res = min(res, cur);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> l >> r >> ql >> qr;
    vector<long long> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << min(try1(w), try2(w));

    return 0;
}