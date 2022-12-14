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

    data.resize(n);

    for (int i = 0; i < n; i++)
        {cin >> data[i]; ans+= data[i];}


    sort(data.begin(), data.end());


    long long left = 0;

    long long cur_ind = data[n-1]+1;

    for (int i = n-1; i > 0; --i)
        {
        left++;
        if (cur_ind > 1) --cur_ind;

        if (data[i-1]+1 >= cur_ind) continue;

        left+= cur_ind - 1 - data[i-1];
        cur_ind = data[i-1]+1;
        }

    left+= max(cur_ind-1, 1ll);


    cout << ans - left;

    return 0;
    }