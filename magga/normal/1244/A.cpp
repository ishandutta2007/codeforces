#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
    a = (a+c-1)/c;b=(b+d-1)/d;
    if(a+b>k){
        cout<<-1<<"\n";
    }else{
        cout<<k-b<<" "<<b<<"\n";
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