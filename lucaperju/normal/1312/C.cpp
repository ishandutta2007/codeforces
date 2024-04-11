#include <bits/stdc++.h>
 
using namespace std;
int v[103];
int fv[503];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,i,j,k;
        cin>>n>>k;
        for(i=0;i<=500;++i)
                fv[i]=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            j=0;
            while(a)
            {
                fv[j]+=a%k;
                a/=k;
                ++j;
            }
        }
        for(i=0;i<=500;++i)
        {
            if(fv[i]>1)
            {
                cout<<"NO\n";
                break;
            }
        }
        if(i==501)
            cout<<"YES\n";
    }
    return 0;
}