#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> ansers (1000);

long long a, b, c, s, k, n, m, tmp, ans = 0, tests;





int main()
    {
    FAST;


    cin >> tests;


    for (int num_test = 0; num_test < tests; num_test++)
        {



        cin >> s >> a >> b >> c;


        ans = (a+b)*(s/(a*c));
        //cout  << ans << " " << (s/(a*c)) << endl;
        s%= (a*c);
        ans+= (s/c);


        ansers[num_test] = ans;
        }



    for (int i = 0; i < tests; i++)
        {
        cout << ansers[i] << endl;
        }

    return 0;
    }