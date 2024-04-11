// resubmission from practice mashup

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
const int mxN=1e6+5;
int n,q,arr[mxN],wao[mxN];
int eat(int x){
    int s=0,ptr=0;
    for(int i=0;i<n;i++){
        while(ptr-i<n&&s+arr[ptr%n]<=x){
            s+=arr[ptr%n];
            ptr++;
        }
        wao[i]=ptr-i;
        s-=arr[i];
    }
    int go=0;
    for(int i=0;i<n;i++){
        if(wao[go]>wao[i])go=i;
    }
    int ans=n;
    for(int i=go;i<=go+wao[go];i++){
        int now=0,pp=i;
        while(pp<i+n){
            now++;
            pp+=wao[pp%n];
        }
        ans=min(ans,now);
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    while(q--){
        int e;
        cin>>e;
        cout<<eat(e)<<"\n";
    }
}