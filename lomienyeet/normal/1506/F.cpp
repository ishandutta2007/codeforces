#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int,int> p[n];
        for(int i=0;i<n;i++)cin>>p[i].first;
        for(int i=0;i<n;i++)cin>>p[i].second;
        sort(p,p+n);
        int l=1,r=1,ans=0;
        for(int i=0;i<n;i++){
            int cur=r-l+p[i].first-p[i].second;
            if(cur&&(!((l+r)&1))){
                cur--;
                l++;
            }
            if(!cur&&(!((l+r)&1)))ans+=p[i].first-l;
            else ans+=(cur+1)/2;
            l=p[i].first;
            r=p[i].second;
        }
        cout<<ans<<"\n";
    }
}