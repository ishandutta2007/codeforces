#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
const long long int N = 1e6+1;
long long int n;
void pre(){}
void solve(){
    long long int m,d;cin>>m;
    set<long long int> arr;
    for(int i=0;i<m;i++){cin>>d;arr.insert(d);}
    long long int a,b;cin>>a>>b;
    n = a-b+1;
    long long int t[n];
    for(long long int i=0;i<n;i++)t[i]=i+1;
    long long int str = 0;
    for(auto i:arr){
        long long int k = b/i;
        if(b%i==0){
            t[0]=max(t[0],min(a-b,(b/i+1)*i-1-b));
        }
        for(long long int j=k+1;i*j<=a;j++){
            if(i*j-b<=a-b)
                t[i*j-b]=max(t[i*j-b],min(a-b,i*j+i-1-b));
            //cout<<i*j<<" ";
        }  
    }
    for(long long int i=1;i<n;i++){
        t[i]=max(t[i-1],t[i]);
    }
    int curr = 0 ;
    int ans = 0;
    int lst = 1;
    int oo = 0;
    while(curr!=a-b && ans<=1000000){
        curr=t[curr];
        ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}