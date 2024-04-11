#include <bits/stdc++.h>

using namespace std;
int rz[2005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=3)
        {
            cout<<-1<<'\n';
            continue;
        }
        if(n==4)
            cout<<"3 1 4 2\n";
        else
        if(n==5)
            cout<<"3 1 4 2 5\n";
        else
        {
            if(n%2==0)
            {
                for(i=1;i+4<=n;i+=2)
                    cout<<i<<' ';
                cout<<i+2<<' '<<i<<' ';
                for(i=n;i>=2;i-=2)
                    cout<<i<<' ';
                cout<<'\n';
            }
            else
            {
                for(i=1;i<=n;i+=2)
                    cout<<i<<' ';
                cout<<n-3<<' '<<n-1<<' ';
                for(i=n-5;i>=2;i-=2)
                    cout<<i<<' ';
                cout<<'\n';
            }

        }
    }
    return 0;
}