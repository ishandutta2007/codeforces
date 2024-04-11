#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, t, tmp, ans = 0;


void solve()
    {
    long double d;
    cin >> d;

    if (d*d - 4*d < 0)
        {
        cout << "N" << endl;
        return;
        }

    long double disk = d*d - 4*d;


    disk = sqrt(disk);
    disk+= d;
    disk/= 2;
    cout << "Y " << disk << " " << (d-disk) << endl;
    }


int main()
    {
    FAST;

    cout << setprecision(14);


    cin >> t;



    for (int i = 0; i < t; i++)
        solve();




    //cout << ans;

    return 0;
    }