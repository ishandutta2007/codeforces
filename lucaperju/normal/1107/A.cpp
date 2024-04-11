#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char c[500];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j,s=0,m,cnt=0,cur,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>ws>>c;
        if(n==2)
        {
            if(c[1]>c[0])
            {
                cout<<"YES\n2\n";
                cout<<c[0]<<' '<<c[1]<<'\n';
            }
            else
                cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n2\n";
            cout<<c[0]<<' ';
            for(i=1;i<n;++i)
                cout<<c[i];
            cout<<'\n';
        }
    }
    return 0;
}