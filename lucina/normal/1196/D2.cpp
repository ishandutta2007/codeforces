#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q,k,qs[maxn],a[maxn];
string s;
string shit="RGB";
bool ch(int x){
    for(int j=0;j<3;j++){
        for(int i=1;i<=n;i++){
            a[i]=(s[i]==shit[(i+j)%3]?1:0);
            qs[i]=qs[i-1]+a[i];
        }
        for(int i=1;i<=n-k+1;i++){
            int cur=qs[i+k-1]-qs[i-1];
            if(cur+x>=k){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n>>k>>s;
        s='#'+s;
        int l=0,r=k,mid,ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(ch(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }

}

/*
    Good Luck
        -Lucina
*/