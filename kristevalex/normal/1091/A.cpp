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


    cin >> a >> b >> k;

    int min_ = min(a+1, min(b, k-1));

    cout << 3*min_;




    //cout << ans;

    return 0;
    }