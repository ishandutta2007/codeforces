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

    long long SQRT = sqrt(n);

    for (long long i = 2; i <= SQRT; i++)
        {
        if (n%i == 0)
            {
            //cout << "iuw";
            cout << 1 + (n-i)/2;
            return 0;
            }
        }





        cout << 1;

        return 0;



    }