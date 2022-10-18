#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    deque<int> c;
    int t, a = 0, b = 0, sa = 0, sb = 0;
    cin >> t;
    while (t--)
    {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    while (!c.empty())
    {
        if (sa == sb && c.size() == 1)
        {
            a++;
            c.pop_back();
        }
        else if (sa == sb)
        {
            a++;
            b++;
            
            sa += c.front();
            sb += c.back();
            c.pop_back();
            c.pop_front();
        }
        else if (sa > sb)
        {
            b++;
            sb += c.back();
            c.pop_back();
        }
        else
        {
            a++;
            sa += c.front();
            c.pop_front();
        }
    }
    cout << a << " " << b;
}