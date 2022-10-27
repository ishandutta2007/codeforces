#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int s=0,e=0,o=0;
        for(int x=1;x<=n;x++)
        {
            int y;
            cin>>y;
            if(y%2==0)e++;
            else o++;
            s+=y;
        }
        while(q--)
        {
            int op,x;
            cin>>op>>x;
            if(op==1)s+=o*x;
            else s+=e*x;
            if(x%2==1)if(op==1)e+=o,o=0;
            else o+=e,e=0;
            cout<<s<<endl;
        }
    }
}