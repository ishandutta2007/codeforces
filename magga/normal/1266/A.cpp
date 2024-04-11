#include<bits/stdc++.h>
using namespace std;
void solve(){
  string s;cin>>s;
  bool f1 = false;
  bool f2 = false;
  int even = 0;
  long long int ans =0;
  for(long long int i=0;i<s.size();i++){
      ans+=int(s[i])-'0';
      if((int(s[i])-int('0'))%2==0 ){
          even++;
      }
      if(s[i]=='0'){
          f2=true;
      }
  }
  //cout<<ans<<"\n";
  if(even>=2 && f2 && ans%3==0){
      cout<<"red"<<"\n";
  }else{
      cout<<"cyan"<<"\n";
  }      
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}