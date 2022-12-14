#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, c, n;



int main()
    {
    FAST;

    cin >> a >> b >> c >> n;


    if (a < c || b < c)
        {
        cout << -1;
        return 0;
        }

    long long l = n - a - b + c;

    if (l <= 0)
        {
        cout << -1;
        return 0;
        }

    cout << l;

    return 0;
    }