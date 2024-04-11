#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200;

int k, n = 0, a = 0, b = 0, c = 0;
int m[max_n];
string s;

bool vis[max_n];

void f(int a)
{
  //  cout << a << endl;
    if (a < 0 || a >= n) return;
    if (vis[a]) return;
    if (s[a] == '#') return;
    vis[a] = true;
    f(a + k);
    f(a - k);
}

int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'G') f(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            if (vis[i])
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    return 0;
}