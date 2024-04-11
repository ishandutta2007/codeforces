#include<bits/stdc++.h>
using namespace std;
//first = location
//second = position
//third = danger
pair<pair<long long int,long long int>,long long int>trap[200001];
long long int m,n,k,t;
bool check(long long int mi){
    long long int till = 0;
    long long int time = n+1;
    for(long long int i=0;i<k;i++){
        //cout<<till<<" "<<trap[i].first.second<<" "<<mi<<" "<<trap[i].second<<"\n";
        if(till<trap[i].first.first){
            till =  trap[i].first.first - 1 ;
        }
        if(mi>=trap[i].second){
            continue;
        }
        if(till>=trap[i].first.second){
            continue;
        }
        //cout<<"hmmm"<<"\n";
        time += (trap[i].first.second-till)*2;
        till = trap[i].first.second;
        
    }
    //cout<<"--------------"<<"\n";
    //cout<<time<<" "<<till<<" "<<mi<<"\n";
    if(time<=t){
        return true; 
    }
    return false;
}
void solve(){
    cin>>m>>n>>k>>t;
   long long int arr[m];
   for(long long int i=0;i<m;i++){
       cin>>arr[i];
   }
   sort(arr,arr+m);
   
   for(long long int i=0;i<k;i++){
       cin>>trap[i].first.first>>trap[i].first.second>>trap[i].second;
   }
   sort(trap,trap+k);
   long long int start = 0;
   long long int end = m;
   long long int mid ;
   while(start<end){
       //cout<<start<<" "<<end<<"\n";
       mid = (start+end+1)/2;
       if(check(arr[m-mid])){
           start = mid;
       }else{
           end = mid-1;
       }
   }
   cout<<start<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}