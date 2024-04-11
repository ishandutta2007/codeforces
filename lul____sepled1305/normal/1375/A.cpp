/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            if(i%2==1)
                cout<<abs(a[i])<<" ";
            else
                cout<<-abs(a[i])<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/