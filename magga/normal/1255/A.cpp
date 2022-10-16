#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b;cin>>a>>b;
    long long int ans = abs(b-a)/5;
    long long int d = abs(b-a)%5;
    if(d==0){
        cout<<ans<<"\n";
    }
    else if(d==1 || d==2){
        cout<<ans+1<<"\n";
    }else{
        cout<<ans+2<<"\n";
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