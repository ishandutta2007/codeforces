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
        int n,m,i,j;
        cin>>n>>m;
        int a[n][m];
        int sol[n][m];
        bool pass = true;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
                int counti = 0;
                if(i!=0)
                    counti++;
                if(i!=n-1)
                    counti++;
                if(j!=0)
                    counti++;
                if(j!=m-1)
                    counti++;

                if(a[i][j]>counti)
                    pass = false, sol[i][j]=0;
                else
                    sol[i][j]=counti;
            }
        }
        if(pass)
        {
            cout<<"YES\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    cout<<sol[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
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