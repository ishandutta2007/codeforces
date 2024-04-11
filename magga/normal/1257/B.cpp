#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,m;cin>>n>>m;
    if(n==1){
        if(m==1){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        return;
    }else if(n==2 || n==3){
        if(m<=3){
            cout<<"YES"<<"\n";
        }
        else{
             cout<<"NO"<<"\n";
        }
    }else{
        cout<<"YES"<<"\n";
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