#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

queue<pair<int, int> > d;
queue<pair<int, int> > r;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] =='D') d.push(make_pair(i, 0));
        else r.push(make_pair(i, 0));
    }
    while (d.size() && r.size())
    {
        if (d.front().second < r.front().second)
        {
            r.pop();
            d.push(make_pair(d.front().first, d.front().second + 1));
            d.pop();
        }
        else if (r.front().second < d.front().second)
        {
            d.pop();
            r.push(make_pair(r.front().first, r.front().second + 1));
            r.pop();
        }
        else
        {
            if (d.front().first < r.front().first)
            {
                r.pop();
                d.push(make_pair(d.front().first, d.front().second + 1));
                d.pop();
            }
            else if (r.front().first < d.front().first)
            {
                d.pop();
                r.push(make_pair(r.front().first, r.front().second + 1));
                r.pop();
            }
        }
    }
    if (d.size())
    {
        cout << "D";
    }
    else
    {
        cout << "R";
    }
    return 0;
}