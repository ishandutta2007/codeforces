#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<pair<int, int>> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    data.resize(2*n);

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data[i] = {-tmp, 0};
        }

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data[i+n] = {-tmp, 1};
        }

    sort(data.begin(), data.end());

    for (int i = 0; i < 2*n; i++)
        {
        //cout << data[i].first << " " << data[i].second << endl;
        if ((i%2) == data[i].second)
            {
            //cout << i << endl;
            if (!data[i].second) ans-= data[i].first;
            else ans+= data[i].first;
            }
        }


    cout << ans;

    return 0;
    }