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
int T;

void solve()
{
    int counti = 1;
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        if(a[i]<=a[i-1])
            a[i]++;
        if(a[i] != a[i-1])
            counti++;
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