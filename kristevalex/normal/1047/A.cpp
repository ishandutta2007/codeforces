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

    if (n%3 == 0 && n%9 != 0)
        {
        cout << n/3 << " " << n/3 << " " << n/3;
        return 0;
        }

    if (n%9 == 0)
        {
        cout << n/3-1 << " " << n/3-1 << " " << n/3+2;
        return 0;
        }

    if (n%3 == 1)
        {
        n--;

        if (n%9 == 0)
            {
            cout << n/3-1 << " " << n/3+1 << " " << n/3+1;
            return 0;
            }

        if ((n/3)%3 == 1)
            {
            cout << n/3 << " " << n/3 << " " << n/3+1;
            return 0;
            }

        if ((n/3)%3 == 2)
            {
            cout << n/3-1 << " " << n/3 << " " << n/3+2;
            return 0;
            }
        }

    if (n%3 == 2)
        {
        n-=2;

        if (n%9 == 0)
            {
            cout << n/3-1 << " " << n/3+2 << " " << n/3+1;
            return 0;
            }

        if ((n/3)%3 == 1)
            {
            cout << n/3 << " " << n/3+1 << " " << n/3+1;
            return 0;
            }

        if ((n/3)%3 == 2)
            {
            cout << n/3 << " " << n/3 << " " << n/3+2;
            return 0;
            }
        }





    return 0;
    }