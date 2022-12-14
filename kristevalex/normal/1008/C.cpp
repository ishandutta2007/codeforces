#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, m, k, ans = 0;


int main()
    {
    FAST;

    cin >> n;

    vector<long long> data (n);
    vector<bool> datab (n, false);


    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        }

    sort(data.begin(), data.end());

    int i = n-1, j = n-1;

    for (; i > 0; i--)
        {
        for (; j >= 0; j--)
            {
            if(!datab[j] && data[i] > data[j]) break;
            }
        if (j < 0) break;
        datab[j] = true;
        ans++;
        }


    cout << ans;

    return 0;
    }