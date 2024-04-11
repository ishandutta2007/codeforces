#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k,d;cin>>n>>k;
    set<long long int>s;
    map<long long int,int>m;
    long long int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        if(i>=k){
            if(m[arr[i-k]]==1){
                s.erase(arr[i-k]);
                m.erase(arr[i-k]);
            }else if(m[arr[i-k]]==2){
                s.insert(arr[i-k]);
                m[arr[i-k]]--;
            }else{
                m[arr[i-k]]--;
            }
        }
        if(m.find(arr[i])!=m.end()){
            m[arr[i]]++;
            s.erase(arr[i]);
        }else{
            s.insert(arr[i]);
            m[arr[i]]++;
        }
        if(i>=k-1){
            if(s.size()!=0)
        cout<<*s.rbegin()<<"\n";
        else
        {
                cout<<"Nothing"<<"\n";
        }
        }
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