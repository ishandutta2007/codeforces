#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back

map<int,int>mp;

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;

    int M=N;
    for(int i=2;i*i<=N;i++){
        while(M%i==0){
            mp[i]++;
            M/=i;
        }
    }
    if(M!=1)mp[M]++;

    int ans=1;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        ans*=it->first;
    }
    cout<<ans<<endl;

    return 0;
}