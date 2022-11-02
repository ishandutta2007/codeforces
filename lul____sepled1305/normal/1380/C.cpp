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
        int n,x,counti = 0,i;
        long long cur = 0;
        cin>>n>>x;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        bool fi = true;
        int mini;
        for(i=0;i<n;i++)
        {
            if(fi)
            {
                fi = false;
                mini = a[i];
                cur = 1 ;
            }
            else
            {
                mini = a[i];
                cur++;
            }

            if(cur*mini >= x)
            {
                fi = true;
                counti++;
            }
        }
        cout<<counti<<"\n";
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/