#include<bits/stdc++.h>
using namespace std;
void solve(){
   long long int n,d;cin>>n;
   set<long long int>s;
   for(long long int i=0;i<n;i++){s.insert(i+1);}
   long long int ans[n];
   long long int arr[n];
   cin>>ans[0];
   arr[0]=ans[0];
   s.erase(ans[0]);
   long long int ref = ans[0];
   for(long long int i=1;i<n;i++){
       cin>>d;
       arr[i]=d;
       if(d>ref){
           ans[i]=d;
           ref=d;
           s.erase(ref);
       }else if(d==ref){
           long long int poop = *s.begin();
           ans[i]=poop;
           s.erase(ans[i]);
       }
   }
   long long int foo = ans[0];
   for(long long int i=0;i<n;i++){
       foo = max(foo,ans[i]);
       if(foo!=arr[i]){
           cout<<-1<<"\n";
           return;
       }
   }
   for(long long int i:ans){
       cout<<i<<" ";
   }
   cout<<"\n";
    
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