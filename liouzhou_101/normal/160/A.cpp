#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[200];

int main()
{
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,tot=0;
    for (int i=n;i>=1;--i)
    {
        ++ans;
        tot+=a[i];
        if (tot>sum-tot) break;
    }
    cout<<ans<<endl;
    return 0;
}