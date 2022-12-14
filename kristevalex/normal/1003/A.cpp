#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, tmp, k, ans = 0;

map<int, int> MAP;


int main()
    {
    FAST;

    cin >> n;


    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        if (!MAP[tmp]) MAP[tmp] = 1;
        else MAP[tmp]++;
        if (MAP[tmp] > ans) ans = MAP[tmp];
        }


    cout << ans;

    return 0;
    }