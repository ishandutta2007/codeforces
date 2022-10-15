#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        long long int N,M;
        cin>>N>>M;
        long long int ans=ceil(N*M/2.0);
        cout<<ans<<endl;
    }
    return 0;
}