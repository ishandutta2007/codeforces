#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
int a[maxn];
ll sum;
ll sum1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>-1;i--)
    {
        sum1+=a[i];
        sum-=a[i];
        if(sum1>sum)
        {
            cout<<n-i;
            return 0;
        }
    }
}