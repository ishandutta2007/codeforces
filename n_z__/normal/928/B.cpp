#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        if(y==0)a[x]=min(k,x-1)+1;
        else a[x]=a[y]+min(k*2+1,x-y);
        cout<<a[x]+min(k,n-x)<<endl;
    }
}