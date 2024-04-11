#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a = 0, b = 0, turn = 0;
        vector<ll> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v.emplace_back(tmp);
        }

        sort(v.begin(), v.end());

        while (!v.empty())
        {
            if (turn == 0) //Alice
                if (v.back() % 2 == 0)
                    a += v.back();

            if (turn == 1) //Bob
                if (v.back() % 2 == 1)
                    b += v.back();

            v.pop_back();
            turn++;
            turn %= 2;
        }
        if (b > a)
            cout << "Bob\n";
        else if (b < a)
            cout << "Alice\n";
        else
            cout << "Tie\n";
    }

    return 0;
}