#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,t,a,b;cin>>n>>t>>a>>b;
    long long int na=0 ,nb=0 ; 
    pair<long long int,long long int>arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i].second; 
        if(arr[i].second==0){
            na++;
        }else{
            nb++;
        }
    }
    for(long long int i=0;i<n;i++){cin>>arr[i].first;}
    sort(arr,arr+n);
    long long int ma = 0;
    long long int mb = 0;
    long long int ans = 0;
    if(na*a+nb*b<=t){
        cout<<n<<"\n";
        return;
    }
    long long int boo,temp;
    for(long long int i=0;i<n-1;i++){
        if(arr[i].second==0){
            ma++;
        }else{
            mb++;
        }
        boo = arr[i+1].first - 1;
        boo -= ma*a;
        boo -= mb*b;
        if(boo<0){
            continue;
        }
        temp = ma+mb;
        temp += min(boo/a,na-ma);
        boo -= min(boo/a,na-ma)*a;
        temp += min(boo/b,nb-mb);
        boo -= min(boo/b,nb-mb)*b;
        if(temp>ans){
            ans=temp;
        }
    }
    if(arr[n-1].second!=n){
        if(arr[n-1].second==0){
            ma++;
        }else{
            mb++;
        }
    }    
    boo = n-1;
    boo -= ma*a;
    boo -= mb*b;
    if(boo>=0){
        temp = ma+mb;
        temp += min( boo/a , na-ma );
        boo -= min(boo/a,na-ma)*a;
        temp += min(boo/b,nb-mb);
        boo -= min(boo/b,nb-mb)*b;
        if(temp>ans){
            ans=temp;
        }
    }
    boo = arr[0].first - 1;
    if(boo>=0){
        temp = 0;
        temp += min(boo/a , na);
        boo -= min(boo/a,na)*a;
        temp += min(boo/b,nb);
        boo -= min(boo/b,nb)*b;
        if(temp>ans){
            ans=temp;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}