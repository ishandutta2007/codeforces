#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,m;cin>>n>>m;
    long long int arr[10];
    arr[0]=0;
    for(long long int i=1;i<10;i++)
    {
        arr[i]=(m*i)%10+arr[i-1];
    }
    long long int ans = arr[9]*(n/(m*10))+ arr[(n/m)%(10)];
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}