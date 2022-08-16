#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int L=1,R=n;
    int ans=n;
    while (L<=R)
    {
        int mid=(L+R)>>1;
        int tmp=mid,sum=0;
        while (tmp)
        {
            sum+=tmp;
            tmp/=k;
        }
        if (sum>=n)
        {
            ans=min(ans,mid);
            R=mid-1;
        }
        else
            L=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}