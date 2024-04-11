// imagine writing 2d bit for 1800
// but then again, its just mxN<<1 bits without any connection

#include <bits/stdc++.h>
using namespace std;
const int mxN=5e2+5;
int bit[mxN<<1][mxN<<1];
void upd(int x,int y,int v){
    for(;y<(mxN<<1);y+=y&-y)bit[x][y]+=v;
}
int qry(int x,int y){
    int ans=0;
    for(;y;y-=y&-y)ans+=bit[x][y];
    return ans;
}
signed main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    upd(0,1,1);
    for(int i=1;i<=n;i++){
        upd(arr[i],arr[i]+1,1);
        for(int j=0;j<=1000;j++){
            if(qry(j,arr[i]))upd(arr[i]^j,arr[i]+1,1);
        }
    }
    vector<int> ans;
    for(int i=0;i<=1000;i++){
        if(qry(i,501))ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)cout<<i<<" ";
}