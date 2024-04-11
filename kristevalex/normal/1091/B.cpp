#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    long long x = 0, y = 0;

    for (int i = 0; i < 2*n; i++)
        {
        cin >> a >> b;
        x+= a;
        y+= b;
        }

    cout << x/n << " " << y/n;



    //cout << ans;

    return 0;
    }