#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    int arr[n],maxi=-2e9;
    map<string,int> mp,ans;
    for(int i=0;i<n;i++){
        cin>>s[i]>>arr[i];
        mp[s[i]]+=arr[i];
    }
    for(int i=0;i<n;i++)maxi=max(maxi,mp[s[i]]);
    for(int i=0;i<n;i++){
        ans[s[i]]+=arr[i];
        if(ans[s[i]]>=maxi&&mp[s[i]]==maxi){
            cout<<s[i]<<"\n";
            return 0;
        }
    }
}