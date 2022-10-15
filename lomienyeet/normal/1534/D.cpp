#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin>>n;
    int arr[n+1],a=0,b=0;
    cout<<"? 1\n";
    fflush(stdout);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i>1){
            a+=(arr[i]&1);
            b+=(!(arr[i]&1));
        }
    }
    bool z=(a<=b);
    vector<int> qry;
    set<pair<int,int> > ans;
    for(int i=2;i<=n;i++){
        if((arr[i]&1)==z)qry.push_back(i);
    }
    for(int i=2;i<=n;i++){
        if(arr[i]==1)ans.insert({1,i});
    }
    for(auto i:qry){
        cout<<"? "<<i<<"\n";
        fflush(stdout);
        for(int j=1;j<=n;j++){
            cin>>arr[j];
            if(arr[j]==1)ans.insert({min(i,j),max(i,j)});
        }
    }
    cout<<"!\n";
    for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
    fflush(stdout);
}