#include<bits/stdc++.h>
using namespace std;
void work()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1);
    for(int x=1;x<=n;x++)
    if(((l-1)/x+1)*x<=r)a[x]=((l-1)/x+1)*x;
    else {cout<<"NO"<<endl;return;}
    cout<<"YES"<<endl;
    for(int x=1;x<=n;x++)
    cout<<a[x]<<' ';
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        work();
    }
}