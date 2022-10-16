#include <bits/stdc++.h>

using namespace std;
int fv[103];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,la,lb,n,m,i,j,a,sc=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        sc+=a;
        if(sc<=m)
            cout<<0<<' ';
        else
        {
            int cat=sc-m;
            int scn=0,rzc=0;
            for(j=100;j>=1;--j)
            {
                if(scn+fv[j]*j>=cat)
                {
                    rzc+=(cat-scn-1)/j+1;
                    break;
                }
                else
                {
                    scn+=fv[j]*j;
                    rzc+=fv[j];
                }
            }
            cout<<rzc<<' ';
        }
        ++fv[a];
    }
    return 0;
}