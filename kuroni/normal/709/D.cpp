#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll x)
{
    ll i = ((ll)sqrt(8*x+1))/2 + 1;
    if (i*(i-1) == x*2) return i; else return -1;
}
string ans(ll zeros, ll ones, ll z)
{
    string str = "";
    while ((zeros > 0) || (ones > 0))
        {
            if (z >= ones)
            {
                str = '0' + str;
                zeros--;
                z -= ones;
            }
            else
            {
                str = '1' + str;
                ones--;
            }
        }
    return str;
}
int main()
{
    ll x, y, z, t, ones, zeros, totals;
    cin>>x>>y>>z>>t;
    if ((x != 0) && (t != 0))
    {
        zeros = solve(x);
        ones = solve(t);
        totals = solve(x+y+z+t);
        if ((zeros == -1) || (ones == -1) || (totals == -1) || (zeros + ones != totals)) {cout<<"Impossible"; return 0;}
        cout<<ans(zeros, ones, z);
        return 0;
    }
    if (x == 0)
    {
        bool chk = 0;
        zeros = 0;
        ones = solve(t);
        totals = solve(x+y+z+t);
        if (!((zeros == -1) || (ones == -1) || (totals == -1) || (zeros + ones != totals))) {cout<<ans(zeros,ones,z); return 0;}
        zeros = 1;
        ones = solve(t);
        totals = solve(x+y+z+t);
        if (!((zeros == -1) || (ones == -1) || (totals == -1) || (zeros + ones != totals))) {cout<<ans(zeros,ones,z); return 0;}
        cout<<"Impossible";
        return 0;
    }
    zeros = solve(x);
    ones = 1;
    totals = solve(x+y+z+t);
    if (!((zeros == -1) || (ones == -1) || (totals == -1) || (zeros + ones != totals))) {cout<<ans(zeros,ones,z); return 0;}
    ones = 0;
    totals = solve(x+y+z+t);
    if (!((zeros == -1) || (ones == -1) || (totals == -1) || (zeros + ones != totals))) {cout<<ans(zeros,ones,z); return 0;}
    cout<<"Impossible";
    return 0;
}