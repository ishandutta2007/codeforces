#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());

    int g=0;
    for(int i=0;i<n;i++)g=__gcd(g,a[i]);

    int b=a[n-1]/g;
    if((b-n)&1)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    return 0;
}