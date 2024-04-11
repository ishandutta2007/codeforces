#include<bits/stdc++.h>
using namespace std;
void solve()
{   //A = 65 a= 97
    long long int ans =0;
    long long int n;cin>>n;
    long long int d=0;
    long long int b=0;
    for(long long int i=0;i<n;i++){
        cin>>b;
        if(b==1){
            d++;
        }
        cin>>b;
        if(b==1){
            d++;
        }
        cin>>b;
        if(b==1){
            d++;
        }
        if(d>=2){
            ans++;
        }
        d=0;
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}