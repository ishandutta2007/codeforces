#include<bits/stdc++.h>
using namespace std;
void solve()
{
  string s;cin>>s;
  if(s.size()<=10){
      cout<<s<<"\n";
  }else{
      cout<<s[0]<<s.size()-2<<s[s.size()-1]<<"\n";
  }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}