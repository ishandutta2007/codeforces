#include <iostream>
#include <stdio.h>
using namespace std;

int n, a[200005], f[200005], s[200005], x;
string t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	s[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = i;
    }
    cin >> t;
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + (int)(t[i - 1]) - 48;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == i) continue;
        if (f[i] > i && s[f[i] - 1] - s[i - 1] == f[i] - i) continue;
        else if (f[i] > i)
        {
            cout << "NO";
            return 0;
        }
        else if (s[i - 1] - s[f[i] - 1] == i - f[i]) continue;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
	return 0;
}