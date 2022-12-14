#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0, cur_h, cur_ind, min_h;


void next_cut()
    {
    long long cur_sum = 0;

    while (true)
        {
        if (cur_h == min_h) break;


        while (cur_ind > 0)
            {
            if (cur_h == data[cur_ind-1]) --cur_ind;
            else break;
            }

        if (cur_sum + (n-cur_ind) > k) break;

        cur_h--;
        cur_sum+= (n-cur_ind);
        }
    }


int main()
    {
    FAST;


    cin >> n >> k;

    data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    sort(data.begin(), data.end());

    min_h = data[0];
    cur_h = data[n-1];
    cur_ind = n-1;


    while (true)
        {
        if (cur_h == min_h)
            {
            cout << ans;
            return 0;
            }

        next_cut();
        ans++;
        }



    return 0;
    }