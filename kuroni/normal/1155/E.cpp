#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1E6 + 3, K = 12;

long long inv[MOD];
vector<long long> ans(K, 0);

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 0; i < p; i++)
        (ret *= u) %= MOD;
    return ret;
}

struct TGauss
{
    vector<long long> ve;
    int fi;

    TGauss(vector<long long> _ve = vector<long long>(K, 0))
    {
        ve = _ve;
        fi = K;
        for (int i = 0; i < K; i++)
            if (ve[i] > 0)
            {
                fi = i;
                break;
            }
    }

    bool valid() { return fi < K; }

    TGauss operator^(const TGauss &oth)
    {
        TGauss ans = *this;
        if (ans.ve[oth.fi] > 0)
        {
            int pos = oth.fi;
            long long coe = ans.ve[pos] * inv[oth.ve[pos]] % MOD;
            for (int i = pos; i < K; i++)
            {
                (ans.ve[i] -= oth.ve[i] * coe) %= MOD;
                (ans.ve[i] += MOD) %= MOD;
            }
            ans.fi = K;
            for (int i = 0; i < K; i++)
                if (ans.ve[i] > 0)
                {
                    ans.fi = i;
                    break;
                }
        }
        return ans;
    }

    bool operator<(const TGauss &oth) const
    {
        return fi < oth.fi;
    }
};
vector<TGauss> ve;

TGauss ask(int u)
{
    vector<long long> ve;
    for (int i = 0; i < K - 1; i++)
        ve.push_back(pw(u, i));
    ve.push_back(0);
    cout << "? " << u << endl;
    cin >> ve.back();
    return TGauss(ve);
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < MOD; i++)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i <= K - 2; i++)
    {
        TGauss cur = ask(i);
        for (TGauss &v : ve)
            cur = cur ^ v;
        if (cur.valid())
        {
            ve.push_back(cur);
            sort(ve.begin(), ve.end());
        }
        else
            break;
    }
    for (int i = K - 2; i >= 0; i--)
    {
        ans[i] = ve[i].ve.back();
        for (int j = i + 1; j <= K - 2; j++)
            (ans[i] -= ve[i].ve[j] * ans[j]) %= MOD;
        (ans[i] *= inv[ve[i].ve[i]]) %= MOD;
    }
    for (int i = 0; i < MOD; i++)
    {
        long long ret = 0;
        for (int j = 0; j <= K - 2; j++)
            (ret += ans[j] * pw(i, j)) %= MOD;
        if (ret == 0)
        {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! -1" << endl;
    return 0;
}