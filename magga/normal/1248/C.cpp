#include<bits/stdc++.h>
using namespace std;
long long int m = 1000000007;
long long int po(long long int x, long long int y) 
{ 
    if (y == 0) 
        return 1; 
    long long int p = po(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
long long int modInverse(long long int a) 
{ 
    long long int g = __gcd(a,m); 
    long long int ans = po(a,m-2);
    return ans;
} 
long long int process(long long int a){
    long long int p=1;
    long long int ans=0;
    //cout<<p<<" ";
    for(long long int i=0;i<a/2;i++){
        p*=(a-2*i);
        p%=m;
        p*=(a-2*i-1);
        p%=m;
        p*=modInverse(i+1);
        p%=m;
        p*=modInverse(a-i);
        p%=m;
        //cout<<p<<" ";
        ans+=p;
    }
    //cout<<endl;
    return ans;
}
void solve()
{
    long long int a,b;
    cin>>a>>b;
    process(10);
    long long int ans = 2*(process(a)+process(b))+2;
    ans%=m;
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num =1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}