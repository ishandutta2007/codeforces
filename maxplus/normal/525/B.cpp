#include <iostream>
#include <string>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main()
{
    string s;
    int m, i, n, sum;
    static int rev[200005];
    cin >> s >> m;
    n = s.size();
    while (m--)
    {
        cin >> i;
        rev[--i]++;
        rev[n - i]++;
    }
    for (int i = 0; i < n; ++i)
    {
        sum += rev[i];
        if (sum & 1)
            cout << s[n - i - 1];
        else
            cout << s[i];
    }
    return 0;
}