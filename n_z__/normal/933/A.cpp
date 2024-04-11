#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q,a1=0,a2=0,a3=0,a4=0;
    cin>>n;
    while(n--)
    cin>>q,a1+=(q==1),a2=max(a1,a2+(q==2)),a3=max(a2,a3+(q==1)),a4=max(a3,a4+(q==2));
    cout<<a4;
}