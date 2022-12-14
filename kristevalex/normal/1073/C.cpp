#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans, x, y;



string text;

int main()
    {
    FAST;


    cin >> n;
    ans = n;

    cin >> text;

    cin >> x >> y;


    if (abs(x) + abs(y) > n)
        {
        cout << -1;
        return 0;
        }

    if ((n - abs(x) - abs(y))%2 == 1)
        {
        cout << -1;
        return 0;
        }


    for (int i = 0; i < n; i++)
        {
        if (text[i] == 'U') --y;
        if (text[i] == 'D') ++y;
        if (text[i] == 'R') --x;
        if (text[i] == 'L') ++x;
        }

    if (x == 0 && y == 0)
        {
        cout << 0;
        return 0;
        }

    int le = -1, re = -1, u = 0, d = 0, l = 0, r = 0;

    for ( ; re < n; )
        {
        for ( ; re < n; )
            {
            long long y_ = y + u - d, x_ = x + r - l;

            long long steps =  u+r+d+l;

            //cout << "u: " << u << ", d: " << d << ", l: " << l << ", r: " << r << ", x_: " << x_ << ", y_: " << y_ << endl;

            if ((steps >= abs(x_) + abs(y_)) && ((steps - abs(x_) - abs(y_))%2 == 0)) break;



            re++;
            if (text[re] == 'U') ++u;
            if (text[re] == 'D') ++d;
            if (text[re] == 'R') ++r;
            if (text[re] == 'L') ++l;
            }

        //if (re != n)
            if (ans >= (re-le))
                {
                ans = (re - le);
                //cout << re << " " << le << endl << ans << endl;
                }

        le++;
        if (text[le] == 'U') --u;
        if (text[le] == 'D') --d;
        if (text[le] == 'R') --r;
        if (text[le] == 'L') --l;
        }

    cout << ans;

    return 0;
    }