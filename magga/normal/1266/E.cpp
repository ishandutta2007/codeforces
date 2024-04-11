#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    int n,a,b,c;cin>>n;
    int arr[n+1];
    long long int ans = 0;
    long long int tar[n+1];
    for(int i=1;i<=n;i++){
        cin>>tar[i];
        ans+=tar[i];
        arr[i]=0;
    }
    map<int,int>garp[n+1];
    int q;cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        if(garp[a].find(b)!=garp[a].end()){
            //cout<<"asdad"<<"\n";
            arr[garp[a][b]]--;
            if(arr[garp[a][b]]<tar[garp[a][b]]){
                ans++;
            }
            garp[a].erase(b);
        }
        if(c==0){
            cout<<ans<<"\n";
            continue;
        }else if(c!=0){
            garp[a][b]=c;
            arr[c]++;
            //cout<<arr[]
            if(arr[c]<=tar[c]){
                ans--;
            }
        }
        cout<<ans<<"\n";
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