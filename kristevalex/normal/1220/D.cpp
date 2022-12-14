#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans_ = 0;



int count2(long long x)
    {
    int ans = 0;
    while (x%2 == 0)
        {
        x/= 2;
        ans++;
        }
    return ans;
    }



int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    int cnt[100] = {};


    for (int i = 0; i < n; i++)
        {
        cnt[count2(data[i])]++;
        }

    for (int i = 0; i < 100; i++)
        {
        if (ans_ < cnt[i])
            {
            ans_ = cnt[i];
            a = i;
            }
        }

    cout << n - ans_ << endl;

    for (int i = 0; i < n; i++)
        {
        if (count2(data[i]) != a)
            cout << data[i] << " ";
        }



    return 0;
    }