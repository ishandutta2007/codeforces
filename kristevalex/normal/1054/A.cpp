#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long x, y, z, t1, t2, t3, a, b, k, n, m, tmp, dist = 0, ansl = 0, ansp = 0;



//#define abs(x) (x>=0)?(x):(-x)

int main()
    {
    FAST;


    cin >> x >> y >> z >> t1 >> t2 >> t3;


    dist = abs(x-y);
    ansp = dist*t1;

    ansl = 3*t3 + dist*t2;
    ansl+= abs(x-z)*t2;



    cout << ((ansl <= ansp)? "YES":"NO");

    return 0;
    }