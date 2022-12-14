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


    if (n < m) swap(n, m);

    if (n == 2 && m == 2)
        {
        cout << m*n - 4;
        return 0;
        }

    if (n == 3 && m == 2)
        {
        cout << m*n - 2;
        return 0;
        }

    if (n == 7 && m == 2)
        {
        cout << m*n - 2;
        return 0;
        }



    if (m == 1)
        {
        int n_6 = n%6;

        //n%= 6;
        int pairs = max(0, (int)n_6-3);
        cout << n*m - (n_6-2*pairs);
        return 0;
        }

    if (true/*n > 7 && m > 1*/)
        {
        cout << m*n - ((m*n) & 1);
        return 0;
        }



    return 0;
    }