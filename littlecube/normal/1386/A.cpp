#include <bits/stdc++.h>
using namespace std;

bool query(long long K)
{
    bool res;
    cout << "? " << K << endl;
    cin >> res;
    return res;
}

long long gfirst(long long N)
{
    if (N <= 3)
        return 1;
    return (N + 1) / 2 + 1 - gfirst((N + 1) / 2);
}

long long solve(long long N, long long extend = 0, long long side = 1, long long current = 1, bool start = 1)
{
    if (start)
        current = gfirst(N);

    if (N == 1)
        return 1;
    else if (N == 2)
    {
        if (start)
            query(current);
        if (query(current + side * 1 + side * extend))
            return 1;
        else
            return 2;
    }
    else if (N == 3)
    {
        if (start)
            query(current);
        if (query(current + side * 2 + side * extend))
        {
            if (query(current + side * 1))
                return 1;
            else
                return 2;
        }
        else
            return 3;
    }

    bool res;
    if (side == 1)
    {
        if (start)
            query(current);
        current = current + N / 2 + extend;
        res = query(current);
    }
    else
    {
        if (start)
            query(current);
        current = current - N / 2 - extend;
        res = query(current);
    }
    if (res)
        return solve(N / 2, extend, -side, current, false);
    else
        return N / 2 + solve(N - N / 2, extend + N / 2, -side, current, false);
}




signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N, C;
        cin >> N;
        C = solve(N);
        cout << "= " << C << endl;
    }
}