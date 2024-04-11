#include<bits/stdc++.h>
using namespace std;
void work()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int x=1;x<=n;x++)
    cin>>a[x];
    for(int x=2;x<=n;x++)
    if(a[x]%a[1]!=0){cout<<"NO"<<endl;return ;}
    cout<<"YES"<<endl;
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