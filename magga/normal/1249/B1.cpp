#include<bits/stdc++.h>
using namespace std;
void solve()
{
  long long int n;cin>>n;
  long long int arr[n];
  queue<pair<long long int,long long int>>q;
  long long int ans[n];
  for(long long int i=0;i<n;i++){ans[i]=-1;}
  for(long long int i=0;i<n;i++){
      cin>>arr[i];
      arr[i]--;
  }
  pair<long long int,long long int>p;
  for(long long int i=0;i<n;i++){
      if(ans[i]==-1){
          long long int j=0;
          p.first=i;
          p.second=j;
          q.push(p);
          //cout<<i<<" "<<j<<endl;
          long long int blu = i;
          while(q.size()!=0){
              j++;
              //cout<<q.size();
            blu = arr[blu];
            if(q.front().first==blu){
                ans[q.front().first]=j-q.front().second;
                q.pop();
            }else{
                p.first=blu;
                p.second=j;
                q.push(p);
            }
            
          }
      }
  }
  for(long long int i=0;i<n;i++){
      cout<<ans[i]<<" ";
  }
  cout<<endl;
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