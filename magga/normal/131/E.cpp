#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m;cin>>n>>m;
    set<int>hor[n+1];
    set<int>ver[n+1];
    set<int>dia1[2*n+1];
    set<int>dia2[2*n+1];
    pair<int,int>arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
        hor[arr[i].first].insert(arr[i].second);
        ver[arr[i].second].insert(arr[i].first);
        dia1[arr[i].first+arr[i].second].insert(arr[i].first);
        dia2[arr[i].first-arr[i].second+n].insert(arr[i].first);
    }   
    int ans[m];
    for(int i=0;i<m;i++){
        ans[i]=0;
        auto j = hor[arr[i].first].lower_bound(arr[i].second); 
        if( (*j)!=*(hor[arr[i].first]).rbegin() ) ans[i]++;
        if( (*j)!=*(hor[arr[i].first]).begin() ) ans[i]++;
        j=ver[arr[i].second].lower_bound(arr[i].first);
        if( (*j)!=*(ver[arr[i].second]).rbegin() ) ans[i]++;
        if( (*j)!=*(ver[arr[i].second]).begin() ) ans[i]++;
        j = dia1[arr[i].first+arr[i].second].lower_bound(arr[i].first);
        if( (*j)!=*(dia1[arr[i].first+arr[i].second]).rbegin() ) ans[i]++;
        if( (*j)!=*(dia1[arr[i].first+arr[i].second]).begin() ) ans[i]++;
        j = dia2[arr[i].first-arr[i].second+n].lower_bound(arr[i].first);
        if( (*j)!=*(dia2[n+arr[i].first-arr[i].second]).rbegin() ) ans[i]++;
        if( (*j)!=*(dia2[n+arr[i].first-arr[i].second]).begin() ) ans[i]++;
    }
    int woo[9]{0};
    for(auto i:ans){
        woo[i]++;
    }
    for(int i=0;i<=8;i++){
        cout<<woo[i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}