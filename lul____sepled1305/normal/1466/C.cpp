/**
    Ithea Myse Valgulious
**/

#include<bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using pll = pair<ll,ll>;
int INF = 1e9;
int T;

void solve()
{
    string s;
    cin>>s;
    int n = s.size(),i,j,counti = 0;
    int a[n];
    for(i=1;i<n;i++)
    {
        if(i == 1 && s[i] == s[i-1])
        {
            s[i] = '?';
            counti++;
        }
        else if(i > 1)
        {
            if(s[i] == s[i-1] || s[i] == s[i-2])
            {
                s[i] = '?';
                counti++;
            }
        }
    }
    cout<<counti<<endl;

}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}