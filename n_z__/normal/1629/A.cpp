#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[101];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int x=1;x<=n;x++)
        cin>>a[x].first;
        for(int x=1;x<=n;x++)
        cin>>a[x].second;
        sort(a+1,a+1+n);
        for(int x=1;x<=n;x++)
        if(a[x].first<=k)k+=a[x].second;else break;
        cout<<k<<endl;
    }
}