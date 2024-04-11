#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data1, data2;

long long a, b, k, n, m, tmp, ans = 0, sum1 = 0, sum2 = 0;





int main()
    {
    FAST;


    cin >> n;

    data1.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data1[i];
        sum1+= data1[i];
        }

    cin >> m;

    data2.resize(m);

    for (int i = 0; i < m; i++)
        {
        cin >> data2[i];
        sum2+= data2[i];
        }

    if (sum1 != sum2)
        {
        cout << -1;
        return 0;
        }

    sum1 = 0;
    sum2 = 0;

    for (int i = 0, j = 0; i < n && j < m; )
        {
        if (sum1 == sum2 && sum1 != 0)
            {
            ans++;
            sum1 = 0;
            sum2 = 0;
            }

        if (sum1 < sum2 || sum1 == 0)
            {
            sum1+= data1[i];
            i++;
            }

        if (sum2 < sum1 || sum2 == 0)
            {
            sum2+= data2[j];
            j++;
            }
        }



    cout << ans+1;

    return 0;
    }