#include<bits/stdc++.h>
using namespace std;
int n,k,l,p,o,m,i,j,ss,h,sb,checki;
int a[800000];
int b[800000];
int c[800000];
int main()
{

    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]==1)
        {
            checki++;
            //cout<<a[i]<<c[2]<<" ";
        }
        if(checki!=n)
        {
            cout<<0;
        }
        else
        {
            cout<<1;
            checki=0;
            for(j=1;j<=n;j++)
            {
                b[j]--;
                if(b[j]>0)
                {
                    checki++;
                }
            }
        }
    }
    return 0;
}