#include<bits/stdc++.h>
using namespace std;
set<long long int>s;
set<long long int>s1;
long long int arr[35];
long long int mod ;
void rec(long long int ret,long long int i,long long int j){
     if( i==j ){
         return;
     }
     s.insert(ret%mod);
     s.insert((ret+arr[i])%mod);
     rec(ret%mod,i+1,j);
     rec((ret+arr[i])%mod,i+1,j);
}
void rec1(long long int ret,long long int i,long long int j){
     if( i==j ){
         return;
     }
     s1.insert(ret%mod);
     s1.insert((ret+arr[i])%mod);
     rec1(ret%mod,i+1,j);
     rec1((ret+arr[i])%mod,i+1,j);
}
void solve(){
    long long int n,m;cin>>n>>m;
    s.insert(0);
    s1.insert(0);
    mod=m;
    for(long long int i=0;i<n;i++){
        cin >> arr[i];
        arr[i] %= m;
    }
    if(n==1){
        cout<<arr[0]<<"\n";
        return;
    }
    rec(0,0,(n+1)/2);
    long long int mx = 0; 
    rec1(0,(n+1)/2,n);
    mx=max(mx,*(s.rbegin()));
    mx=max(mx,*(s1.rbegin()));
    s.insert(m);
    s1.insert(m);
    for(long long int i:s1){
        if(s.find(m-1-i) != s.end()){
            cout<<m-1<<"\n";
            return;
        }else{
            auto p = s.upper_bound(m-1-i)--;
            mx = max(mx,(i+*p)%mod);
            if(*p!=0){
                p--;
                mx = max(mx,(i+*p)%mod);
            }    
        }
    }
    cout<<mx<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}