#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    vector<ll> prime = {2};

    for (ll i = 3; i <= 1e5; i += 2)
    {
        bool is_prime = true;
        for (auto j : prime)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
            if (j > sqrt(i))
                break;
        }
        if (is_prime)
        {
            prime.emplace_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        vector<ll> dec = {1};
        cin >> n;
        for (ll i = 0; i < prime.size() && n != 1; i++)
        {
            ll count = 0;
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                if (count >= dec.size())
                {
                    dec.emplace_back(prime[i]);
                }
                else
                {
                    dec[count] *= prime[i];
                }
                count++;
            }
        }
        if (n != 1)
        {
            dec.front() *= n;
        }
        sort(dec.begin(), dec.end());
        cout << dec.size() << '\n';
        for (auto i : dec)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
}