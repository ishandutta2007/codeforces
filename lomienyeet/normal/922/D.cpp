// i agree with ic

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.ff*b.ss>a.ss*b.ff;
}
signed main(){
    int n,ans=0;
    cin>>n;
    pair<int,int> p[n+1];
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        p[i]={0,0};
        for(char c:s){
            if(c=='s')p[i].ff++;
            else{
                p[i].ss++;
                ans+=p[i].ff;
            }
        }
    }
    sort(p+1,p+n+1,cmp);
    int z=p[1].ff;
    for(int i=2;i<=n;i++){
        ans+=z*p[i].ss;
        z+=p[i].ff;
    }
    cout<<ans<<"\n";
}