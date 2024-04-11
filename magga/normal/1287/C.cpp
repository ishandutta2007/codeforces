#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int pos = (n+1)/2;
    long long int nev = n/2;
    long long int arr[n];
    long long int coo = 0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=0){
            if(arr[i]%2==0){
                nev--;
            }else{
                pos--;
            }
        }
        if(arr[i]==0){
            coo++;
        }
    }
    if(coo==n && n!=1){
        cout<<1<<"\n";
        return;
    }else if(n==1){
        cout<<0<<"\n";
        return;
    }
    long long int ans = 0 ;
    bool flag = false ;
    long long int hist = 0;
    long long int last = 0;
    multiset<pair<long long int,long long int>>s;
    for(long long int i=0;i<n;i++){
        if(arr[i]!=0 && flag){
            if( hist%2 ==  arr[i]%2 && last != i-1 ){
                s.insert(make_pair(i-last-1,arr[i]%2));
            }else if( hist%2 !=  arr[i]%2 ){
                ans+=1;
            }
            last = i;
            hist = arr[i]%2;
        }else if( arr[i]!=0 && !flag ){
            flag = true;
            hist = arr[i]%2;
            last = i;
        }
    }
    for(auto i : s){
        //cout<<i.first<<" "<<i.second<<"\n";
        if( i.second == 0 ){
            if( i.first > nev ){
                ans+=2;
            }else{
                nev-=i.first;
            }
        }else{
            if( i.first > pos ){
                ans+=2;
            }else{
                pos-=i.first;
            }
        }
    }
    long long int init = 0; 
    long long int end = 0;
    while(arr[n-1-end]==0){
        end++;
    }
    while(arr[init]==0){
        init++;
    }
    if(arr[init]%2==0){
        if(nev<init){
            ans++;
        }else{
            nev-=init;
        }
    }else{
        if(pos<init){
            ans++;
        }else{
            pos-=init;
        }
    }
    //cout<<end<<" "<<init<<"\n";;
    if(arr[n-1-end]%2==0){
        if(nev<end){
            ans++;
        }else{
            nev-=end;
        }
    }else{
        if(pos<end){
            ans++;
        }else{
            pos-=end;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}