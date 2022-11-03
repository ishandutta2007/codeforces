#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res , t = 1 , ans;
bool isp[maxn];
vector<int>p;
bool check(int n)
{
    for(int i = 0; i < p.size(); i++)
    {
        if(n == p[i])
            return 1;
        if(n % p[i] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    for(ll i = 2; i < maxn; i++)
    {
        if(isp[i] == 0)
        {
            for(ll j = i * i; j < maxn; j += i)
            {
                isp[j] = 1;
            }
            p.pb(i);
        }
    }
    if(n != 2 && n % 2 == 0)
    {
        cout << 2;
        return 0;
    }
    if(check(n))
        cout << 1;
    else if(check(n - 2))
        cout << 2;
    else
        cout << 3;
}