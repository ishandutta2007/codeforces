#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
#define x first
#define y second
pair<int,int>b[100001];
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int now=1;
        for(int x=1;x<=n;x++)
        cin>>a[x],b[x].x=a[x],b[x].y=x;
        sort(b+1,b+1+n);
        for(int x=2;x<=n;x++)
        if(b[x].y!=b[x-1].y+1)now++;
        //cout<<now<<endl;
        if(now>k)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}