#include <iostream>
using namespace std;
int main()
{
    int n,d,res=0;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        while(a[i]<=a[i-1])
        {
            int c=(a[i-1]-a[i])/d;
            a[i]+=c*d;
            if(a[i-1]>=a[i])
            {a[i]+=d; res++;}
            res+=c;
        }
    }
    cout<<res;
}