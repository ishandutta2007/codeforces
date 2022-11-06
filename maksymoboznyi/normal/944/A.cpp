#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long

using namespace std;

const int N = 1e5+5;
const ll inf = 2e18;
int n, a, b;
signed main()
{
    int kol = 0;
    cin >> n >> a >> b;
    while (a != b)
    {
        a= (a-1)/2+1;
        b = (b-1)/2+1;
        kol++;
    }
    if ((1<<kol) == n)
        cout << "Final!";
    else
        cout << kol;
    return 0;
}