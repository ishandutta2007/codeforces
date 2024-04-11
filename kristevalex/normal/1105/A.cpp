#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 1e9;



int ans_id = 1;

int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];


    for (int i = 1; i < 100; i++)
        {
        int cur = 0;
        for (int j = 0; j < n; j++)
            {
            cur+= max(0ll, abs(data[j] - i) - 1);
            }
        if (cur < ans ) {ans = cur; ans_id = i;}
        }




    cout << ans_id << " " << ans;

    return 0;
    }