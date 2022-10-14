#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,v[N],t[N],pre[N];
multiset<int>ms;
signed main(){
	ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>t[i],pre[i]=pre[i-1]+t[i];
    for(int i=1;i<=n;i++){
        int ans=0;
        ms.insert(v[i]+pre[i-1]);
        while(!ms.empty()&&*ms.begin()<=pre[i])
            ans+=*ms.begin()-pre[i-1],ms.erase(ms.begin());
        ans+=t[i]*ms.size();
        cout<<ans<<" ";
    }
}