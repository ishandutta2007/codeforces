#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define next FUCK_STD

using namespace std;
typedef long long ll;
typedef long double ld;

const unsigned int max_n = 1000005;

int next[max_n];
bool vis[max_n];
bitset<max_n> b1, b2;

vector<int> sz;
vector<int> ruc;

void add(int a, int num)
{
    int curs = 1;
    while (curs <= num)
    {
        ruc.push_back(curs * a);
        num -= curs;
        curs *= 2;
    }
    if (num)
    {
        ruc.push_back(a * num);
    }
}

int main()
{
    //ifstream cin("input.txt");
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", next + i);
        next[i]--;
    }

    int len, cur;

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            cur = next[i];
            len = 1;
            while (!vis[cur])
            {
                len++;
                vis[cur] = true;
                cur = next[cur];
            }
            sz.push_back(len);
        }
    }

    sort(sz.begin(), sz.end());
    int num = 1;
    for (int i = 1; i < sz.size(); ++i)
    {
        if (sz[i] == sz[i - 1])
        {
            num++;
        }
        else
        {
            add(sz[i - 1], num);
            num = 1;
        }
    }
    add(sz[sz.size() - 1], num);

    b1[0] = true;
    for (int i = 0; i < ruc.size(); ++i)
    {
        b2 = (b1 << ruc[i]);
        b1 |= b2;
        /*for (int j = n; j >= ruc[i]; --j)
        {
            dp[j] |= dp[j - ruc[i]];
        }*/
    }

    if (b1[k])
    {
        cout << k << ' ';
    }
    else
    {
        cout << k + 1 << ' ';
    }

    int mans = 0;
    for (int i = 0; i < sz.size(); ++i)
    {
        if (k == 0)
        {
            break;
        }
        if (sz[i] / 2 < k)
        {
            k -= sz[i] / 2;
            mans += (sz[i] / 2) * 2;
        }
        else
        {
            mans += k * 2;
            k = 0;
        }
    }

    for (int i = 0; i < sz.size(); ++i)
    {
        if (k == 0)
        {
            break;
        }
        if (sz[i] % 2 == 1)
        {
            k--;
            mans++;
        }
    }

    cout << mans;

    return 0;
}