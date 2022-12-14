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


    cin >> n;

    data.resize(n);

    long long Min = 1000000000000;

    bool all_same = true;

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        ans+= abs(data[i]);
        if (abs(data[i]) < Min) Min = abs(data[i]);

        if (data[0]*data[i] <= 0) all_same = false;
        }


    if (n == 1)
        {
        cout << data[0];
        return 0;
        }


    if (!all_same || n == 1) cout << ans;
    else cout << ans - 2*Min;

    return 0;
    }