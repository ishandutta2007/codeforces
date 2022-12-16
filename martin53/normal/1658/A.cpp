#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;

    int prv=-1;

    int outp=0;

    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;

        if(c=='0')
        {
            if(prv!=-1)outp+=max(0,3-(i-prv));
            prv=i;
        }
    }

    return outp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}