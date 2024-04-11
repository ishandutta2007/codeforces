#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0, r, l;





int main()
    {
    FAST;


    cin >> l >> r;

    data.resize(n);


    cout << "YES" << endl;
    for (long long i = l; i < r; i+= 2)
        {
        cout << i << " " << i+1 << endl;
        }



    //cout << ans;

    return 0;
    }