#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    int r[1010];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n; i++)
    {
        int color[1010] = {0};
        queue<int> l;
        l.push(i);
        color[l.front()] = 1;
        while (!l.empty())
        {
            color[l.front()] = 2;
            if (color[r[l.front()]] == 2)
            {
                cout << r[l.front()] << " \n"[i == n];
                break;
            }
            else
            {
                l.push(r[l.front()]);
                color[r[l.front()]] = 1;
            }
            l.pop();
        }
    }
}