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

    if (n<=2)
        {
        cout << "No";
        return 0;
        }


    cout << "Yes" << endl;
    cout << 2 << " " << 1 << " " << n << endl;
    cout << n-2 << " ";
    for (int i = 2; i < n; i++)
        {
        cout << i << " ";
        }


    return 0;
    }