/* instead of playing cf round, i thought trying to do one "hard" q for practice would be better?
since my math is ~blue-purple (and trash), i try to solve red nt in 2 hours... see if i fail
pretend this is noi so i only get one submission */

// i tried my best ok, but i still needed 1.5 hours to do this + half an hour to duipai... im really so bad at math

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5,mod=1e9+7;
int fact[mxN],inv[mxN],freq[mxN],phi[mxN];
bool vis[mxN],ok[mxN];
vector<int> v[mxN];
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
int ncr(int n,int r){
    if(n<r)return 0;
    else return (((fact[n]*inv[n-r])%mod)*inv[r])%mod;
}
signed main(){
    int n,k,q,ans=0;
    cin>>n>>k>>q;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        freq[x]++;
    }
    for(int i=1;i<mxN;i++){
        for(int j=i*2;j<mxN;j+=i)freq[i]+=freq[j];
    }
    vector<int> pp;
    phi[1]=1;
    for(int i=2;i<mxN;i++){
        if(!vis[i]){
            pp.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<pp.size()&&i*pp[j]<mxN;j++){
            vis[i*pp[j]]=1;
            if(!(i%pp[j])){
                phi[i*pp[j]]=phi[i]*pp[j];
                break;
            }
            else phi[i*pp[j]]=phi[i]*phi[pp[j]];
        }
    }
    fact[0]=inv[0]=1;
    for(int i=1;i<mxN;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=bm(fact[i],mod-2);
    }
    for(int i=1;i<mxN;i++)(ans+=(phi[i]*ncr(freq[i],k))%mod)%=mod;
    int arr[q+1];
    for(int i=1;i<=q;i++){
        cin>>arr[i];
        ok[arr[i]]=1;
    }
    for(int i=1;i<mxN;i++){
        for(int j=i;j<mxN;j+=i){
            if(ok[j])v[j].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        for(auto j:v[arr[i]]){
            (ans+=(phi[j]*(ncr(freq[j]+1,k)-ncr(freq[j],k)+mod)%mod)%mod)%=mod;
            freq[j]++;
        }
        cout<<ans<<"\n";
    }
}