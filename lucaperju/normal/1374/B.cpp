#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        int cnt2=0,cnt3=0;
        while(n%2==0)
        {
            ++cnt2;
            n/=2;
        }
        while(n%3==0)
        {
            ++cnt3;
            n/=3;
        }
        if(n!=1)
        {
            cout<<-1<<'\n';
        }
        else
        if(cnt2>cnt3)
            cout<<-1<<'\n';
        else
            cout<<cnt3+cnt3-cnt2<<'\n';
    }
    return 0;
}