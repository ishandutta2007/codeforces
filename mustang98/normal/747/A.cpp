#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    //ifstream cin("input.txt");
    int n, ansa,ansb;
    cin >> n;
    int dif = 1e9 + 10;
    for (int a = 1; a <= n; a++)
    {
        int b = n / a;
        if (n % a) continue;
        if (a > b) break;
        if (b - a < dif)
        {
            dif = b - a;
            ansa = a;
            ansb = b;
        }
    }
    cout << ansa << ' ' << ansb;
    return 0;
}