#include<bits/stdc++.h>
using namespace std;
void solve()
{
  long long int n;cin>>n;
  long long int arr[n];
  for(long long int i=0;i<n;i++){cin>>arr[i];}
  sort(arr,arr+n);
  bool b = false;
  for(long long int i=0;i<n-1;i++){
    if(arr[i+1]==arr[i]+1){
      b = true;
      break;
    }
  }
  if(b){
    cout<<2<<"\n";
  }else{
    cout<<1<<"\n";
  }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}