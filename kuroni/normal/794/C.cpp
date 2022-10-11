#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

string s, t, ans_s = "", ans_t = "", ans;
int n, i;
deque <char> a, b;

int main()
{
    ios_base::sync_with_stdio(); cin.tie();
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    n = s.size();
    for (i = 0; i < (n + 1) / 2; i++)
        a.push_back(s[i]);
    for (i = 0; i < n / 2; i++)
        b.push_back(t[i]);
    for (i = 0; i < n; i++)
    {
        if (!(i & 1))
        {
            if (!a.empty() && a.front() >= b.front())
            {
                ans_t += a.back();
                a.pop_back();
            }
            else
            {
                ans_s += a.front();
                a.pop_front();
            }
        }
        else
        {
            if (!b.empty() && a.front() >= b.front())
            {
                ans_t += b.back();
                b.pop_back();
            }
            else
            {
                ans_s += b.front();
                b.pop_front();
            }
        }
    }
    reverse(ans_t.begin(), ans_t.end());
    ans = ans_s + ans_t;
    cout << ans;
}