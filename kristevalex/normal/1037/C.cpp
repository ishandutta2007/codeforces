#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long  k, n, tmp, ans = 0;


string a, b;


int main()
    {
    FAST;


    cin >> n >> a >> b;


    for (int i = 0; i < n; i++)
        {
        if (i != n-1)
            {
            if (a[i] != b[i] && a[i] != a[i+1] && a[i+1] != b[i+1])
                {
                ans++;
                i++;
                continue;
                }
            }
        if (a[i] != b[i]) ans++;
        }



    cout << ans;

    return 0;

    }