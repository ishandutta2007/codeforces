#include<bits/stdc++.h>
using namespace std;
void pre(){
}
void solve(){
    long long int n,c,k,d;cin>>n>>c>>k;
    set<long long int>s;
    for(long long int i=0;i<k;i++){
        cin>>d;s.insert(d);
    }
    s.insert(0);
    s.insert(n+1);
    auto k1 = s.lower_bound(c);
    long long int forr = 0;
    long long int becc = 0;
    long long int ref = c;
    while(*k1==ref && ref!=n+1){
        k1++;
        ref++;
        forr++;
    }
    if(ref==n+1){
        forr=n+1;
    }
    k1 = s.lower_bound(c);
    ref = c;
    while(*k1==ref && ref!=0){
        k1--;
        ref--;
        becc++;
    }
    if(ref==0){
        becc=n+1;
    }
    cout<<min(forr,becc)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}