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


    cin >> n >> m;


    long long _ans = 0;
    for (long long i = 1; i <= m; i++)
        {
        for (long long j = 1; j <= m; j++)
            {
            if ((i*i + j*j) % m == 0) {++_ans; /*cout << 1;*/}
            }
        }
    ans+= (n/m)*(n/m)*_ans;

    _ans = 0;
    for (long long i = 1; i <= n%m; i++)
        {
        for (long long j = 1; j <= m; j++)
            {
            if ((i*i + j*j) % m == 0) {++_ans; /*cout << 2;*/}
            }
        }
    ans+= (n/m)*2*_ans;


    _ans = 0;
    for (long long i = 1; i <= n%m; i++)
        {
        for (long long j = 1; j <= n%m; j++)
            {
            if ((i*i + j*j) % m == 0) ++_ans;
            }
        }
    ans+= _ans;




    cout << ans;

    return 0;
    }