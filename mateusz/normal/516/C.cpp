#include <bits/stdc++.h>

using namespace std;
const int N = 300006, LOG = 18;
const long long INF = 1e18;
long long dist[N], pref[N], height[N];
int repLewo[N][LOG + 2];
int repPrawo[N][LOG + 2];
int n, m, a, b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> dist[i];
        dist[n + i] = dist[i];
    }
    for(int i = 1; i <= 2 * n; i++)
    {
        pref[i] = pref[i - 1] + dist[i - 1];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> height[i];
        height[i] *= 2;
        height[n + i] = height[i];
    }
    height[0] = height[2 * n + 1] = INF;
    for(int i = 0; i <= LOG; i++)
    {
        repLewo[0][i] = 0;
        repPrawo[2 * n + 1][i] = 2 * n + 1;
    }
    for(int i = 1; i <= 2 * n; i++)
    {
        int w = i - 1;
        while(w >= 1 && height[w] < height[i] + pref[i] - pref[w])
            w = repLewo[w][0];
        repLewo[i][0] = w;
        for(int j = 1; j <= LOG; j++)
        {
            repLewo[i][j] = repLewo[repLewo[i][j - 1]][j - 1];
        }
        
    }
    
    for(int i = 2 * n; i >= 1; i--)
    {
        int w = i + 1;
        while(w <= 2 * n && height[w] < height[i] + pref[w] - pref[i])
            w = repPrawo[w][0];
        repPrawo[i][0] = w;
        for(int j = 1; j <= LOG; j++)
        {
            repPrawo[i][j] = repPrawo[repPrawo[i][j - 1]][j - 1];
        }
    }
    while(m--)
    {
        cin >> a >> b;
        if(a > b)
            b += n;
        int x = LOG;
        int w = b + 1;
        long long wynik = 0;
        while(x >= 0)
        {
            if(repPrawo[w][x] < a + n)
                w = repPrawo[w][x];
            x--;
        }
        int pamietaj = w;
        int y = LOG;
        w = a + n - 1;
        while(y >= 0)
        {
            if(repLewo[w][y] > pamietaj)
                w = repLewo[w][y];
            y--;
        }
        int A, B;
        B = w;
        A = pamietaj;
        if(A < B)
            wynik = height[A] + height[B] + pref[B] - pref[A];
        w = a + n - 1;
        y = LOG;
        while(y >= 0)
        {
            if(repLewo[w][y] > b)
                w = repLewo[w][y];
            y--;
        }
        pamietaj = w;
        x = LOG;
        w = b + 1;
        while(x >= 0)
        {
            if(repPrawo[w][x] < pamietaj)
                w = repPrawo[w][x];
            x--;
        }
        A = w;
        B = pamietaj;
        if(A < B)
            wynik = max(wynik, height[A] + height[B] + pref[B] - pref[A]);
        cout << wynik << endl;
    }
    
    
    return 0;
}