#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt3=0,cnt5=0,cnt=0;
            while(n%3LL==0)
            {
                n/=3LL;
                ++cnt3;
            }
            while(n%5LL==0)
            {
                n/=5LL;
                ++cnt5;
            }
            while(n%2LL==0)
            {
                n/=2LL;
                ++cnt;
            }
            if(n==1)
                cout<<cnt+cnt3*2+cnt5*3;
            else
            {
                cout<<-1;
            }
            cout<<'\n';
    }
    return 0;
}