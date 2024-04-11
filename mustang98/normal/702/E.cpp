#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_n = 100009, max_logk = 40;

ll n, k, a;

int p[max_n][max_logk];
ll minn[max_n][max_logk];
ll sum[max_n][max_logk];

vector<int> fact_k;

void factorize(ll k)
{
    for (int i = 0; i < max_logk; i++)
    {
        if (k & (1LL << i))
        {
            fact_k.push_back(i);
        }
    }
}

int main()
{
    scanf("%I64d %I64d", &n, &k);
    factorize(k);

    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &p[i][0]);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &a);
        sum[i][0] = a;
        minn[i][0] = a;
    }

    for (int j = 1; j < max_logk; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int anc = p[i][j - 1];
            p[i][j] = p[anc][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[anc][j - 1];
            minn[i][j] = min(minn[i][j - 1], minn[anc][j - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ll ansSum = 0, ansMin = 1e10;
        int cur = i;
        for(int j = 0; j < fact_k.size(); j++)
        {
            int next = fact_k[j];
            ansSum += sum[cur][next];
            ansMin = min(ansMin, minn[cur][next]);
            cur = p[cur][next];
        }
        //cout << ansSum << ' ' << ansMin << endl;
        printf("%I64d %I64d\n", ansSum, ansMin);
    }

    return 0;
}