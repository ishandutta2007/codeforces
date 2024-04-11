#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e3 + 3;

int a[4];

signed main()
{
    cin >> a[1] >> a[2] >> a[3];
    int mx = 1;
    if (a[2] > a[1] && a[2] > a[3])
        mx = 2;
    if (a[3] > a[1] && a[3] > a[2])
        mx = 3;
    int y, id;
    int sum = a[1] + a[2] + a[3];
    cout << "First" << endl;

    ///first
    y = 3 * a[mx] - sum;
    cout << y << endl;
    cin >> id;
    if (id != mx) {
        int j = 1;
        for (int i = 1; i <= 3; i++)
            if (i != id && i != mx)
                j = i;
        cout << a[mx] - a[j] << endl;
        cin >> id;
        return 0;
    }
    a[mx] += y;
    sum += y;
    y =  3 * a[mx] - sum;
    cout << y << endl;
    cin >> id;
    int j = 1;
    for (int i = 1; i <= 3; i++)
        if (i != id && i != mx)
            j = i;
    cout << a[mx] - a[j] << endl;
    cin >> id;

    return 0;
}