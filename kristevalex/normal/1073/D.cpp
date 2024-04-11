#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, k, n, m, tmp, ans = 0, money, sum = 0;



int main()
    {
    FAST;


    cin >> n >> money;

    queue<long long> data;

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data.push(tmp);
        sum+= tmp;
        }


    while (true)
        {
        long long loops = money/sum;
        ans+= loops*data.size();
        money-= loops*sum;

        if (data.size() == 1) break;

        while (true)
            {
            long long cur = data.front();
            data.pop();

            if (cur > money)
                {
                sum-= cur;
                break;
                }
            else
                {
                ans++;
                money-= cur;
                data.push(cur);
                }
            }
        }





    cout << ans;

    return 0;
    }