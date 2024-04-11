#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    //ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    set<string> s;
    string a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        s.insert(a);
    }
    int ob = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        if (s.count(a))
        {
            ob++;
        }
    }

    int p = n - ob;
    int np = m - ob;

    bool isp = true;

    while(true)
    {
        if (ob)
        {
            ob--;
            isp = !isp;
            continue;
        }
        if (isp)
        {
            if (p)
            {
                p--;
                isp = !isp;
                continue;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        else
        {
            if (np)
            {
                np--;
                isp = !isp;
                continue;
            }
            else
            {
                cout << "YES";
                return 0;
            }
        }
    }

    return 0;
}