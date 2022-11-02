#include <algorithm>
#include <iostream>

using namespace std;

const long long INF = (long long)1e18;
const int N = 100 * 1000 + 10;

long long d[N], h[N], t[N];
long long K[N], B[N];
long long prevDp[N];
long long curDp[N];
long long phi[N];
long long sum[N];
int hull[N];

bool bad(int a, int b, int c)
{
    long long fa = (B[b] - B[c]) * K[a] + B[a] * (K[c] - K[b]);
    long long fb = (B[b] - B[c]) * K[b] + B[b] * (K[c] - K[b]);
    return fa >= fb;
}

long long get_cost(int l, int r)
{
    return K[r] * phi[l] + B[r] - sum[l] + phi[l] * l;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, p;
    cin >> n >> m >> p;
    d[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> d[i];
        d[i] = d[i] + d[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> h[i] >> t[i];
        --h[i];
    }

    for (int i = 0; i < m; i++)
        phi[i] = -t[i] + d[h[i]];
    sort(phi, phi + m);
    sum[0] = 0;
    for (int i = 1; i <= m; i++)
        sum[i] = phi[i - 1] + sum[i - 1];

    fill(prevDp, prevDp + m, INF);
    prevDp[m] = 0;
    for (int curP = 0; curP < p; curP++)
    {
        fill(curDp, curDp + m, INF);

        int sz = 0;
        hull[sz++] = m;

        for (int i = 0; i <= m; i++)
        {
            K[i] = -i;
            B[i] = sum[i] + prevDp[i];
        }

        int ptr = 0;
        for (int i = m - 1; i >= 0; --i)
        {
            while (ptr + 1 < sz && get_cost(i, hull[ptr + 1]) <= get_cost(i, hull[ptr]))
                ptr++;
            curDp[i] = get_cost(i, hull[ptr]);
            if (prevDp[i] != INF)
            {
                while (sz >= 2 && bad(i, hull[sz - 1], hull[sz - 2]))
                    sz--;
                ptr = min(ptr, sz - 1);
                hull[sz++] = i;
            }
        }

        copy(curDp, curDp + m, prevDp);
    }

    cout << curDp[0];

    return 0;
}