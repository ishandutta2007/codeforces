// what the fuck???

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    int n,m,p,ans=0;
    cin>>n>>m>>p;
    int arr[n]={};
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='1')arr[i]|=(1ll<<j);
        }
    }
    for(int i=0;i<150;i++){ // sui ji da fa
        int wa=(32768*rand()+rand())%n;
        srand(rand());
        vector<int> e;
        for(int j=0;j<m;j++){
            if(arr[wa]>>j&1)e.push_back(j);
        }
        int z=e.size(),zz=(1ll<<z),freq[zz]={};
        for(int j=0;j<n;j++){
            int msk=0;
            for(int k=0;k<e.size();k++){
                if(arr[j]>>e[k]&1)msk|=(1ll<<k);
            }
            freq[msk]++;
        }
        for(int j=0;j<z;j++){
            for(int k=0;k<zz;k++){
                if(k>>j&1)freq[k^(1ll<<j)]+=freq[k];
            }
        }
        for(int j=0;j<zz;j++){
            if(freq[j]>=(n+1)/2&&__builtin_popcountll(j)>__builtin_popcountll(ans)){
                ans=0;
                for(int k=0;k<z;k++){
                    if(j>>k&1)ans|=(1ll<<e[k]);
                }
            }
        }
    }
    for(int i=0;i<m;i++)cout<<(ans>>i&1);
    cout<<"\n";
}