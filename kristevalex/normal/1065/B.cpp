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


    cin >> n >> m;

    long long _min = n;

    if (n == 1)
        {
        cout << 1 << " " << 1 << endl;
        return 0;
        }

    if (m > n/2) _min = 0;
    else
        {
        _min = n - 2*m;
        }


    long long low = 0;
    long long high = n+1;
    while (high - low > 1)
        {
        long long middle = (low + high)/2;
        if ((n-middle)*(n-middle-1)/2 >= m)
            low = middle;
        else
            high = middle;
        //cout << (n-middle)*(n-middle-1)/2 << " " << middle << endl;
        }


    cout << _min << " " << low << endl;

    return 0;
    }