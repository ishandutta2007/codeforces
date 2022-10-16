#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int i = 0;cin>>i;
    if(i==0){
        cout<<4<<"\n";
    }else if(i==1){
        cout<<3<<"\n";
    }else if(i==2){
        cout<<2<<"\n";
    }else if(i==3){
        cout<<1<<"\n";
    }else if(i%2==0){
        cout<<0<<"\n";
    }else if(i%2==1){
        cout<<1<<"\n";
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