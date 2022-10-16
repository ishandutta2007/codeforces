#include <bits/stdc++.h>
using namespace std;
bool check(long long int k,long long int p,long long int c,vector<long long int>&v){
    if(c==-1){
        return true;
    }
    while(c>=k-1){
        p-=v[c];
        c-=k;
    }
    while(c>=0){
        p-=v[c];
        c--;
    }
    if(p>=0){
        return true;
    }
    return false;
}
void solve(){
    long long int d,n,p,k;cin>>n>>p>>k;
    vector<long long int>v;
    for(long long int i=0;i<n;i++){
        cin>>d;
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    long long int ans=0;
    long long int start=0,end = (n)/k , mid=0;
    while(start<=end){
        mid=(start+1+end)/2;
        if(check(k,p,mid*k-1,v)){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    long long int aa =0;
    start = max(ans*k-1,aa);
    long long int pro = ans*k;
    end=min((ans+1)*k-1,n-1);
    while(start<=end){
        mid=(start+1+end)/2;
        if(check(k,p,mid,v)){
            pro=mid+1;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout<<pro<<"\n";
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