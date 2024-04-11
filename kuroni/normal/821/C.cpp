#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

string s;
int n, t, i, ans = 0;
bool chk = 0;
stack <int> d;
priority_queue < int, vector <int>, greater <int> > pq;

int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    cin >> n;
    for (i = 1; i <= 2 * n; i++)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> t;
            d.push(t);
            pq.push(t);
        }
        else
        {
            if (d.empty())
            {
                pq.pop();
                continue;
            }
            if (d.top() == pq.top())
            {
                pq.pop();
                d.pop();
            }
            else
            {
                while (!d.empty())
                    d.pop();
                pq.pop();
                ++ans;
            }
        }
    }
    cout << ans;
}