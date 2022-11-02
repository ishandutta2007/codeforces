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
        int n,i,j,mini = 1e9,maxi=0;
        bool found = false;
        bool pass = true;
        vector<int> prv;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            if(mini>a[i])
            {
                if(mini!=1e9)
                    prv.push_back(mini);
                mini = a[i];
            }
            if(a[i]==1)
                found = true;
        }
        maxi = a[n-1];
        while(!prv.empty())
        {
            int node = prv.back();
            if(node > maxi)
                pass = false;
            prv.pop_back();
        }
        if(pass)
            cout<<"YES\n";
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