#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<long long> data_;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m >> k;

    ans+= n;
    data.resize(n);
    //data_.resize(n-1);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 1; i < n; i++)
        {
        if (data[i] == data[i-1]) {--ans; continue;}
        data_.push_back(data[i] - data[i-1] - 1);
        }

    sort(data_.begin(), data_.end());

    if (k >= data_.size() + 1)
        {
        cout << ans;
        return 0;
        }

    for (int i = 0; i < data_.size() + 1 - k; i++)
        {
        ans+= data_[i];
        }




    cout << ans;

    return 0;
    }