#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
bool cmp(int x,int y)
{
    return x>y;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int x=1;x<=n;x++)
        cin>>a[x];
        sort(a+1,a+1+n,cmp);
        int ans=a[1];
        int now=0;
        for(int x=2;x<=n;x++)
        now+=a[x];
        printf("%.9f\n",1.0*ans+1.0*now/(n-1));
    }
}