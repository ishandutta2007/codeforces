#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


string text1, text2;


int main()
    {
    FAST;


    cin >> n >> k;

    cin >> text1 >> text2;

    long long ans1 = 0, ans2 = 0;

    int i = 0;


    for ( ; i < n; i++)
        {
        ans1*= 2;
        ans1+= (text1[i]-'a');

        ans2*= 2;
        ans2+= (text2[i]-'a');

        ans2-= ans1;
        ans1 = 0;


        if (ans2-ans1+1 > k )
            {
            cout << ans+k*(n-i);
            return 0;
            }

        ans+= min(ans2-ans1+1, k);
//cout << ans1 << " " << ans2 << " " << min(ans2-ans1+1, k) << endl;
        }


    cout << ans;

    return 0;
    }