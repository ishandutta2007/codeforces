#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,mod=998244353;
int arr[mxN],ps[mxN],ps2[mxN];
int nom(int l,int r,int x,int y){
    int ans=0;
    for(int i=l;i<=r;i++){
        int lb=i-1,rb=r;
        while(lb<rb){
            int mid=(lb+rb+1)>>1,o=x+ps[i-1]-ps[l-1],v=y+ps[r]-ps[mid];
            if(i&1){
                o+=ps2[mid]-ps2[i-1];
                v+=ps[mid]+ps2[i-1]-ps2[mid]-ps[i-1];
            }
            else{
                o+=ps[mid]+ps2[i-1]-ps2[mid]-ps[i-1];
                v+=ps2[mid]-ps2[i-1];
            }
            if(o<v)lb=mid;
            else rb=mid-1;
        }
        (ans+=(lb-i+1)>>1)%=mod;
    }
    return ans;
}
void eat(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ps[i]=ps[i-1]+arr[i];
        ps2[i]=ps2[i-1]+((i&1)?arr[i]:0);
    }
    int lb=1,rb=n;
    while(lb<rb){
        int mid=(lb+rb)>>1;
        if(ps[mid]>ps[n]-ps[mid])rb=mid;
        else lb=mid+1;
    }
    cout<<(n+nom(1,n,0,0)+nom(1,n-1,arr[n],0)+nom(2,n,0,arr[1])+nom(2,n-1,arr[n],arr[1])-rb+1)%mod<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}