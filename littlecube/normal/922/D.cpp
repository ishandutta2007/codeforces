#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool comp(pair<string, double> p1, pair<string, double> p2)
{
    return p1.second > p2.second;
}

vector<pair<string, double>> v;

int main()
{
    fast;
    ll n, r = 0, sumh = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        int s = 0, h = 0;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == 's')
                s++;
            else
                h++;
        }
        sumh += h;
        v.emplace_back(make_pair(str, (double)(s - h) / (double)str.length()));
    }

    sort(v.begin(), v.end(), comp);

    for (auto i : v)
        for (int j = 0; j < i.first.length(); j++)
            if (i.first[j] == 'h')
                sumh--;
            else
                r += sumh;

    cout << r;
}