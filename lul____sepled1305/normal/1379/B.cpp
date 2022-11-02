#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        long long l,r,m,i;
        cin>>l>>r>>m;
        if(m<=l)
            cout<<l<<" "<<l<<" "<<2*l-m<<"\n";
        else if(m<=r)
            cout<<m<<" "<<r<<" "<<r<<"\n";
        else
        for(i=l;i<=r;i++)
        {
            if(m%i<=r-l)
            {
                cout<<i<<" "<<r<<" "<<r-(m%i)<<"\n";
                break;
            }
            else if(m%i>=i+l-r)
            {
                int res = m%i-i;
                cout<<i<<" "<<r+res<<" "<<r<<"\n";
                break;
            }
        }
    }
}