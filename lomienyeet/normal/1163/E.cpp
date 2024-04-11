#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    bool vis[727727]={0};
    vis[0]=1;
    int ptr=0,ans=0;
    vector<int> sus;
    for(int i=0;i<n;i++){
        while(arr[i]>=(1<<ptr))ptr++;
        if(!vis[arr[i]]){
            for(int j=0;j<(1<<ptr);j++){
                if(vis[j])vis[j^arr[i]]=1;
            }
            sus.push_back(arr[i]);
        }
        if(sus.size()==ptr)ans=ptr;
    }
    cout<<ans<<"\n";
    int xs=0;
    cout<<xs<<" ";
    for(int i=1;i<(1<<ans);i++){
        xs^=sus[__builtin_ctz(i)];
        cout<<xs<<" ";
    }
}