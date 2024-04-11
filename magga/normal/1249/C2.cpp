#include<bits/stdc++.h>
using namespace std;
long long int db[41];
void solve()
{
  long long int n,m;cin>>n;
  m=n;
  long long int max = 4052555153018976268;
  for(long long int i=40;i>=1;i--){
      //cout<<i<<" "<<db[i]<<endl;
      
      if(2*n>db[i] && n>db[i-1])
      {
          m += db[i] - n;
          break;
      }else if(2*n<db[i] && n>db[i-1])
      {
          n-=db[i-1];
      } 
  }
  cout<<m<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    db[0]=1;
    db[1]=1;
    for(long long int i=1;i<40;i++){
        db[i]=db[i-1]*3;
        //cout<<db[i]<<" ";
    }
    //cout<<endl;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}