#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int l=1,r=n-1;

    while(l!=r)
    {
        int av=(l+r)/2+1;

        int c=n-av%n;

        cout<<"+ "<<c<<endl;
        fflush(stdout);

        l+=c;
        r+=c;

        int cur;
        cin>>cur;

        int low=n*cur;
        int high=n*cur+n-1;

        l=max(l,low);
        r=min(r,high);
    }

    cout<<"! "<<l<<endl;
    fflush(stdout);

    return 0;
}