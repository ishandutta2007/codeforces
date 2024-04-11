#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<long long> data_cnt;
vector<long long> data_max;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;


    data_cnt.resize(n);
    data_max.resize(n);

    long long tot_max = -1;

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data.resize(tmp);
        long long _max = -1;
        for (int j = 0; j < tmp; j++)
            {
            cin >> data[j];
            if (data[j] > _max) _max = data[j];
            }
        data_max[i] = _max;
        data_cnt[i] = tmp;
        if (_max > tot_max) tot_max = _max;

        }

    for (int i = 0; i < n; i++)
        {
        ans+= data_cnt[i]*(tot_max - data_max[i]);
        }


    cout << ans;

    return 0;
    }