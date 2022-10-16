#include <iostream>

using namespace std;

int a[256], ans;

int main()
{
    int n;
    char t;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        (cin >> t), a[t]++;
        cin >> t;
        t = tolower(t);
        if (a[t])
            a[t]--;
        else
            ans++;
    }
    cout << ans;
    return 0;
}