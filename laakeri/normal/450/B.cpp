#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll x,y,n,v;
    cin>>x>>y>>n;
    n=(n-1)%6;
    if (n==0) v=x;
    if (n==1) v=y;
    if (n==2) v=y-x;
    if (n==3) v=-x;
    if (n==4) v=-y;
    if (n==5) v=x-y;
    while (v<0) v+=1000000007;
    v%=1000000007;
    cout<<v<<endl;
}