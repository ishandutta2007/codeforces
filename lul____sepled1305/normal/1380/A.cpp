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
        int n,i,index;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        bool pass = false;
        for(i=1;i<n-1;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
                index  = i, pass = true;
        }
        if(pass)
            cout<<"YES\n"<<index<<" "<<index+1<<" "<<index+2<<"\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/