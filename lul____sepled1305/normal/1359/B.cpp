/*Nephren is the nice girl.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,m,x,y,i,j,ans=0;
        cin>>n>>m>>x>>y;
        string s;
        bool good = false;
        if(y<2*x)
            good = true;
        for(i=0;i<n;i++)
        {
            cin>>s;
            int cur=0;
            for(j=0;j<m;j++)
            {
                if(s.at(j)=='.')
                    cur++;
                else
                {
                    if(good)
                        ans+= (cur/2) * y + (cur%2) * x;
                    else
                        ans += cur*x;
                    cur = 0;
                }
            }
            if(good)
                ans+= (cur/2) * y + (cur%2) * x;
            else
                ans += cur*x;
        }
        cout<<ans<<"\n";
    }
    return 0;
}