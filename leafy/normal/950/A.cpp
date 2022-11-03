#include<iostream>
#include<cstdio>
using namespace std;
int l,r,a;
int main()
{
    cin>>l>>r>>a;
    if(l>r) swap(l,r);
    if(a<=r-l) cout<<2*(l+a);
    else cout<<((a-r+l)/2+r)*2;
    return 0;
}