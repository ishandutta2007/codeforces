#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,l,r;cin>>n>>l>>r;l--;r--;
    long long int val = 1;
    long long int start = 0;
    while(start+2*(n-val)<=l && val<=n-1){
        start+=2*(n-val);
        val++;
    }
    //cout<<start<<"\n";
    long long int oo = start;
    long long int ans[1000001];
    int index = 0;
    while(start<=r && val<=n){
        for(int i=val+1;i<=n;i++){
            ans[index]=val;
            index++;
            ans[index]=i;
            index++;
        }
        start+=2*(n-val);
        val++;
    }
    ans[index]=1;
    index++;
    for(long long int i=oo;i<=r;i++){
        if(i>=l){
            cout<<ans[i-oo]<<" ";
        }
    }
    cout<<"\n";
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