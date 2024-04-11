#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,n,s;cin>>a>>b>>n>>s;
    long long int d = min(a,s/n);
    long long int ans = d*n;
    if(s-ans<=b){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
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