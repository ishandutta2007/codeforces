#include <bits/stdc++.h>
using namespace std;
void eat(){
    int n;
    cin>>n;
    n--;
    if(n&1)cout<<n/2<<" "<<n-n/2<<" 1\n";
    else if((n/2)&1)cout<<n/2-2<<" "<<n/2+2<<" 1\n";
    else cout<<n/2-1<<" "<<n/2+1<<" 1\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)eat();
}