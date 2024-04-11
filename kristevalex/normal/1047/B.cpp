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

    for (int i = 0; i < n; i++)
        {
        cin >> data[i] >> tmp;
        data[i]+= tmp;
        }


    sort(data.begin(), data.end());

    cout << data[n-1];

    return 0;
    }