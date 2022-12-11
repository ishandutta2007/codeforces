#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    ll mx=-1,xm=1e10;
    for (int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        mx=max(mx,x),xm=min(xm,x);
    }
    cout<<mx-xm+1-n;
}