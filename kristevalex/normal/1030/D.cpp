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


    cin >> n >> m >> k;

    long long m_old = m;
    long long n_old = n;


    if (k == 1)
        {
        cout << "NO";
        return 0;
        }

    long long GCD1 = __gcd(n, k);
    n/= GCD1;
    k/= GCD1;

    long long GCD2 = __gcd(m, k);
    m/= GCD2;
    k/= GCD2;

    if (k > 2)
        {
        cout << "NO";
        return 0;
        }

    if (k == 1)
        {
        k = 2;

        if (n < n_old)
            {
            n*= 2;
            }
        else m*= 2;
        }

    cout << "YES" << endl;

    cout << 0 << " " << 0 << endl;
    cout << n << " " << 0 << endl;
    cout << 0 << " " << m << endl;








    return 0;
    }