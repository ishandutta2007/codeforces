#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1][m+1],xs=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(j==1)xs^=arr[i][j];
        }
    }
    if(xs){
        cout<<"TAK\n";
        for(int i=1;i<=n;i++)cout<<"1 ";
        return 0;
    }
    vector<int> ans;
    bool ok=0;
    for(int i=1;i<=n;i++)ans.push_back(1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]!=arr[i][1]){
                ans[i-1]=j;
                ok=1;
                break;
            }
        }
        if(ok)break;
    }
    if(ok){
        cout<<"TAK\n";
        for(auto i:ans)cout<<i<<" ";
    }
    else cout<<"NIE\n";
}