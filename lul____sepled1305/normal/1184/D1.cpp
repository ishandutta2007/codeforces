#include<bits/stdc++.h>
using namespace std;
long long n,k,m,l,t,i,j;
int main()
{
    cin>>n>>k>>m>>t;
    for(i=1;i<=t;i++)
    {
        int o,p;
        cin>>o>>p;
        if(o==1)
        {
            if(p<=k)
            {
                k++;
                n++;
            }
            else
            {
                n++;
            }
        }
        else
        {
            if(p>=k)
            {
                n=p;
            }
            else
            {
                n=n-p;
                k-=p;
            }
        }
        cout<<n<<" "<<k<<"\n";
    }
    return 0;
}