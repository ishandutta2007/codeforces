#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,m,d;cin>>n>>m;
    long long int arr[n+1];
    for(long long int i=0;i<n;i++){
        cin>>d;
        arr[d]=i+1;
    }
    long long int ans = 0 ;
    long long int visited = 1 ; 
    for(long long int i=0;i<m;i++){
        cin>>d;
        visited=max(visited,i+1);
        if( arr[d] > visited ){
            ans+=2*(arr[d] - i - 1 )+1;
            visited=arr[d];
        }else{
            ans+=1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}