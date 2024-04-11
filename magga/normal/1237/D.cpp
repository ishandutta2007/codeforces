#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
  long long int n;cin>>n;
  long long int arr[3*n];
  long long int ans[3*n];
  long long int mi = 1e10,ma=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    arr[n+i]=arr[i];
    arr[2*n+i]=arr[i];
    mi = min(arr[i],mi);
    ma = max(ma,arr[i]);
    ans[i]=0;
  }
  if(mi*2>=ma){
    for(int i=0;i<n;i++){
      cout<<-1<<" ";
    }
    cout<<"\n";
    return;
  }
  int j = 0;
  priority_queue<pair<long long int,long long int>>pq;
  for(int i=0;i<3*n;i++){
    pq.push({arr[i],i});
    while(pq.size()>0 && pq.top().first>2*arr[i]){
      for(;j<=pq.top().second;j++){
        ans[j]=i-j;
      }
      pq.pop();
    }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
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