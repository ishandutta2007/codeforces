#include <bits/stdc++.h>

using namespace std;

const int N = 3333;

int d[N][N];
int p[N];
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = N;
    d[0][1] = 0;
    queue<pair<int, int> > q;
    q.push(pair<int, int> (0, 1));
    int rAny = n - 1;
    while (rAny >= 0 && p[rAny] == 0)
        rAny--;
    int rAll = n - 1;
    while (rAll >= 0 && p[rAll] != 100)
        rAll--;
    //cerr << rAll << endl;
    while (!q.empty())
    {
        pair<int, int> ab = q.front();
        q.pop();
        int a = ab.first;
        int b = ab.second;
        //cerr << a << " " << b << endl;
        if (b == n)
            continue;
        //kill the first one only.
        if (rAny >= b && p[a] < 100)
        {
            int toA = b;
            int toB = b + 1;
            if (d[toA][toB] > d[a][b] + 1)
            {
                d[toA][toB] = d[a][b] + 1;
                q.push(pair<int, int> (toA, toB));
            }
        }
        //kill the second only.
        if (rAll < b && p[a])
        {
            int toA = a;
            int toB = b + 1;
            if (d[toA][toB] > d[a][b] + 1)
            {
                d[toA][toB] = d[a][b] + 1;
                q.push(pair<int, int> (toA, toB));
            }
        }
        //kill both.
        if (rAny >= b && p[a])
        {
            int toA = b + 1;
            int toB = b + 2;
            if (d[toA][toB] > d[a][b] + 1)
            {
                d[toA][toB] = d[a][b] + 1;
                q.push(pair<int, int> (toA, toB));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (d[i][j] <= k)
                res++;

    cout << res;

    return 0;
}