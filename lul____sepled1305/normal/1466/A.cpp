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
    int n,i,j;
    cin>>n;
    set<int> st;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            st.insert(abs(a[i]-a[j]));
        }
    }
    cout<<st.size()<<"\n";
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