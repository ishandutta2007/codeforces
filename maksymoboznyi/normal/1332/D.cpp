#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, k;
string s;
int kol[N][27];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int mn = 1;
    while (mn <= k)
        mn *= 2;
    cout << "3 3\n";
    cout << mn + k << ' ' << mn + k << ' ' << mn <<"\n";
    cout << mn + k<< ' ' << k << ' ' << mn + k <<"\n";
    cout << mn << ' ' << mn + k << ' ' << k <<"\n";

    return 0;
}