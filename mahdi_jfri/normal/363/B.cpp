#include <iostream>
using namespace std;
int main()
{
    int n,k,i,a[150000],sum=0,mini,j=1;
    cin>>n>>k;
    for(i=0;i<k;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
    mini=sum;
    for(;i<n;i++)
    {
        cin>>a[i];
        sum-=a[i-k];
        sum+=a[i];
        if(sum<mini)
            {
                mini=sum;
                j=i-k+2;
            }
    }
    cout<<j;
}