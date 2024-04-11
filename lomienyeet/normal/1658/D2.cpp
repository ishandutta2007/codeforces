#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e6+5;
int trie[2][mxN],cnt=1;
void upd(int x){
    int ptr=0;
    for(int i=16;i>=0;i--){
        if(!trie[!!(x&(1<<i))][ptr])trie[!!(x&(1<<i))][ptr]=cnt++;
        ptr=trie[!!(x&(1<<i))][ptr];
    }
}
int qry(int x,int v){
    int ptr=0,ans=0;
    for(int i=16;i>=0;i--){
        if(v){
            if(trie[!(x&(1<<i))][ptr]){
                ptr=trie[!(x&(1<<i))][ptr];
                ans+=1<<i;
            }
            else ptr=trie[!!(x&(1<<i))][ptr];
        }
        else{
            if(trie[!!(x&(1<<i))][ptr])ptr=trie[!!(x&(1<<i))][ptr];
            else{
                ptr=trie[!(x&(1<<i))][ptr];
                ans+=1<<i;
            }
        }
    }
    return ans;
}
void eat(){
    for(int i=0;i<min(mxN,cnt);i++)trie[0][i]=trie[1][i]=0;
    cnt=1;
    int l,r,x;
    cin>>l>>r;
    x=r-l+1;
    int arr[x];
    for(int i=0;i<x;i++){
        cin>>arr[i];
        upd(arr[i]);
    }
    for(int i=0;i<x;i++){
        int z=arr[i]^l;
        if(l<=qry(z,0)&&qry(z,1)<=r){
            cout<<z<<"\n";
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}