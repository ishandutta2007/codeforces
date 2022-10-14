#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,a[N];
int main(){
    ios::sync_with_stdio(0);
    for(cin>>t;t--;){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<a[1]<<"\n";
    }
}