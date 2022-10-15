#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n+1],s=0;
    for(int i=1;i<=n;i++)cin>>arr[i];
    map<int,int> mp;
    for(int i=1,x=0;i<=n;i++){
        if(i&1){
            x+=arr[i];
            mp[arr[i]-x]++;
            while(mp.size()){
                auto e=mp.begin()->first+x;
                if(e<0)mp.erase(mp.begin());
                else break;
            }
        }
        else{
            x-=arr[i];
            mp[-arr[i]-x]++;
            while(mp.size()){
                auto e=mp.rbegin()->first+x;
                if(e>0)mp.erase(mp.find(mp.rbegin()->first));
                else break;
            }
        }
        s+=mp[-x];
    }
    cout<<s<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}