#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n,l,r,t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        if(a==b)
        {
            cout<<"0 0\n";
            continue;
        }
        cout<<(b-a)<<' '<<min(a%(b-a),(b-a)-a%(b-a))<<'\n';
    }
    return 0;
}