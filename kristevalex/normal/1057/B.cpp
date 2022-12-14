#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

vector<long long> _data;

long long a, b, k, n, m, tmp, ans = 0;


bool check (long long l, long long st)
    {
    long long sum = 0;
    sum = _data[l+st] - _data[st];

    //cout << sum << endl;

    if (sum > 100 * l) return true;

    return false;
    }



int main()
    {
    FAST;


    cin >> n;

    data.resize(n);
    _data.resize(n+1);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    _data[0] = 0;
    for (int i = 0; i < n; i++)
        {
        _data[i+1] = _data[i] + data[i];
        }




    for (int i = n; i > 0; i--)
        {
        long long sum = 0;

        for (int j = 0; j <= n-i; j++)
            {
            if (check(i, j))
                {
                cout << i;
                return 0;
                }
            }
        }




    cout << 0;

    return 0;
    }