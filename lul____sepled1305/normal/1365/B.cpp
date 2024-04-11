/**uu is a magic to connect with mother.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,j;
        cin>>n;
        int a[n],b[n];
        bool pass = true;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i>=1 && a[i]<a[i-1])
                pass = false;
        }
        bool first = false, second = false;
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]==0)
                first = true;
            if(b[i]==1)
                second = true;
        }

        if(pass)
            cout<<"Yes\n";
        else if(first&&second)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }
    return 0;
}