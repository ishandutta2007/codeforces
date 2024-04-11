#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, m, k, ans = 0;


int main()
    {
    FAST;

    cin >> n >> k;
    k*=2;

    vector<long long> data (n);


    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        }

    for (int i = 0; i < n-1; i++)
        {
        if ((data[i+1] - data[i]) > k) {ans+= 2; /*cout << i<< endl;*/}
        if ((data[i+1] - data[i]) == k) {ans++; /*cout << i << endl;*/}

        }


    cout << ans+2;

    return 0;
    }