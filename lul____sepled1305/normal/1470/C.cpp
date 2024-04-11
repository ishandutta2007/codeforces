#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,k;
    cin>>n>>k;
    int wait = sqrt(n), space = wait - 1, l = 5*n;
    while(wait--)
    {
        cout<<"? 1\n";
        int r;
        cout.flush();
        cin>>r;
    }
    for(i=1;i<=n+space;i+=space)
    {
        cout<<"? "<<(i-1)%n + 1<<' '<<"\n";
        cout.flush();
        int p;
        cin>>p;
        if(p > k)
            l = min(l,i);
    }
    int mini = l - space, maxi = l,p;
    while(mini < maxi)
    {
        int mid = mini + maxi >> 1;
        if(mid == mini)
        {
            cout<<"? "<<((maxi-1)%n+n)%n+1<<"\n";
            cout.flush();
            cin>>p;
            if(p <= k)
                mini = maxi;
            else
                maxi = mini;
        }
        else
        {
            cout<<"? "<<((mid-1)%n+n)%n+1<<"\n";
            cout.flush();
            cin>>p;
            if(p <= k)
                mini = mid;
            else
                maxi = mid;
        }
    }
    cout<<"! "<<((mini-1)%n + n)%n+1<<"\n";
    cout.flush();
}