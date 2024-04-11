#include<bits/stdc++.h>
using namespace std;
const long long int N = 1e6;
long long int n;
long long int t[2*N]{0},b[2*N]{0};
long long int combine(long long int &a,long long int &b){
    return a+b;
}
void modify(long long int p,long long int value){
    long long int pp = p;
    for(t[p+=n]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
    p=pp;
    for(b[p+=n]=1;p>1;p>>=1){
        b[p>>1]=combine(b[p],b[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}
long long int query1(long long int l,long long int r){
    long long int ret = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,b[l++]);
        if(r&1) ret=combine(b[--r],ret);
    }
    return ret;
}
void pre(){}
void solve(){
    cin>>n;
    long long int arr[n];
    long long int val[n];
    for(int i=0;i<n;i++){cin>>arr[i];val[i]=arr[i];}
    map<long long int,int> hash;
    sort(val,val+n);
    for(int i=0;i<n;i++) hash[val[i]]=i;
    long long int ans = 0;
    for(long long int i=n-1;i>=0;i--){
        ans+=query(0,hash[arr[i]]);
        //cout<<query1(0,hash[arr[i]])<<" "<<hash[arr[i]]<<" "<<"\n";
        modify(hash[arr[i]],query1(0,hash[arr[i]]));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}