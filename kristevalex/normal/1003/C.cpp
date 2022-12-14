#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, k;
double ans = 0;


int main()
    {
    FAST;

    cin >> n >> k;

    vector<long long> data (n);


    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        }


    for (int i = k; i <= n; i++)
        {

        double sum;
        sum = 0;

        for (int j = 0; j < i; j++)
            {
            sum+= data[j];

            }

        if (ans < sum/i) ans = sum/i;

        //printf ("%lf\n" , ans);

        for (int j = i; j < n; j++)
            {
            sum-= data[j-i];
            sum+= data[j];

            if (ans < sum/i) ans = sum/i;

           // printf ("%lf\n" , ans);

            }
        }


    cout.precision(10);

    cout <<  ans;

    return 0;
    }