#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
  vector<string>ans;
  string s;cin>>s;
  //cout<<s.size()<<"\n";
  int i =s.size()-1;
  string oo;
  for(auto j:s){
    if(j!='0'){
    oo=j;
    for(int k=0;k<i;k++){
      oo+='0';
    }
    ans.pb(oo);
    }
    //cout<<" ";
    i--;
  }
  cout<<ans.size()<<"\n";
  for(auto i:ans){
    cout<<i<<" ";
  }
  cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
      //  cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}