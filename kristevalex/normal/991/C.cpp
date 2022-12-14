#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)



bool check_ (long long value, long long quantity)
    {
    long long diff = 0;

    while (quantity)
        {
        if (quantity >= value)
            {
            diff+= value;
            quantity-= value;
            }
        else
            {
            diff+= quantity;
            quantity = 0;
            }


        diff-= quantity/10;
        quantity -= quantity/10;
        }

    return (diff >= 0);
    }


long long n;



int main()
    {
    FAST;

    cin >> n;

    long long low = 0;
    long long high = 100000000000000000;
    while (high - low > 1)
        {
        long long middle = (low + high)/2;
        if (check_(middle, n))
            high = middle;
        else
            low = middle;
        }

    cout << high;

    return 0;
    }