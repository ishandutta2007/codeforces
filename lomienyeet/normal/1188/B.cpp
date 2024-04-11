#include <bits/stdc++.h>
using namespace std;
#define int long long
int bm(int b,int p,int m){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
signed main(){
    int n,p,k;
    cin>>n>>p>>k;
    map<int,int> mp;
    int x=0;
    for(int i=0,u;i<n;i++){
        cin>>u;
        int wao=bm(u,4,p),wao2=(u*k)%p,wao3=(wao-wao2+p)%p;
        x+=mp[wao3];
        mp[wao3]++;
    }
    cout<<x<<"\n";
}