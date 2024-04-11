#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n,s=0,rz=0,a,b;
    int k,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(i=1;i<=a;++i)
        {
            for(j=1;j<=b;++j)
            {
                if(i==1 && j==1)
                    cout<<'W';
                else
                    cout<<'B';
            }
            cout<<'\n';
        }
    }
    return 0;
}