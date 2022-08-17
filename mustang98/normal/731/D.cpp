#include <bits/stdc++.h>

using namespace std;

const int max_n = 500009, max_c = 1000009;

vector<int> v[max_n];
int l[max_n];

int open[max_c], close[max_c];
int n, c, a;

void addSegm(int start, int finish)
{
    open[start]++;
    close[finish]++;
}

void func(int a, int b)
{
    if (a < b)
    {
        int x = c - b;
        addSegm(0, x);
        a += x + 1;
        // x+1 ---- x+1+c-a BAD
        addSegm(x + 2 + c - a, c - 1);
    }
    else
    {
        int x = c - a;
        //0 -- x BAD
        b += x + 1;
        addSegm(x + 1, x + 1 + c - b);
    }
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", l + i);
        for (int j = 0; j < l[i]; j++)
        {
            scanf("%d", &a);
            v[i].push_back(a);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0;;j++)
        {
            if (j == l[i])
            {
                addSegm(0, c - 1);
                break;
            }
            if (j == l[i + 1])
            {
                cout << "-1";
                return 0;
            }
            if (v[i][j] != v[i + 1][j])
            {
                func(v[i][j], v[i + 1][j]);
                break;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < c; i++)
    {
        k += open[i];
        if (k == n - 1)
        {
            cout << i << "\n";
            return 0;
        }
        k -= close[i];
    }
    cout << "-1\n";
    return 0;
}