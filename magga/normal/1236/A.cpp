#include<bits/stdc++.h>
using namespace std;
long long int process(long long int &a,long long int &b){
    long long int d = 0;
    long long int flu = 0;
    if(2*a<=b){
        d += 2*a;
        d += a;
        a = 0;
        b -= 2*a;
    }else{
        d += b/2;
        flu = d;
        d += b - b%2;
        b = b%2;
        a = a - flu;
    }
    return d;
}
void solve()
{
    long long int a,b,c;cin>>a>>b>>c;
    long long int d = 0;
    d+=process(b,c);
    d+=process(a,b);
    cout<<d<<endl;
    
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num =1;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}