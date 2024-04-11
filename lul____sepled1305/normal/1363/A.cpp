/*Chtholly is the best girl.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int x,n,i,odd=0,even=0,k;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>k;
            if(k%2==1)
                odd++;
            else
                even++;
        }
        if(even==0)
        {
            if(x%2==0)
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
        else if(odd>0)
        {
            if(x!=n)
                cout<<"Yes\n";
            else if(odd%2==1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}