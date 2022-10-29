

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,ii,iii)for(int i=ii;i<iii;i++)
#define RFOR(i, init, end) for(int i = end-1; i >= init; i--)
#define OUT(a)cout<<a<<endl
#define ALL(s) s.begin(),s.end()
#define PB push_back
#define ANS(a) OUT(res.size());for(auto i:a)cout<<i<<" ";ENDL
#define PRINT(a,init,end) FOR(i,init,end) cout<<a[i]<<" ";ENDL
#define PRINTV(a) for(auto i:a)cout<<i<<" ";ENDL
#define F first
#define S second

const int N=150000+15;
int n;
const int M=44723;
pair<int,int>a[N];
set<int>divn;
void genDiv(int n) {
  divn.insert(n);
	for(int i=2; i <= M; i++) {
    if(!(n%i))divn.insert(i);
    while(!(n%i))n/=i;
  }
}
void crop(int p) {
  vector<int>to_erase;
  for(int i:divn)if(((a[p].F)%i)&&((a[p].S)%i))to_erase.PB(i);
  for(int i:to_erase)divn.erase(i);
}
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  FOR(i,0,n)cin>>a[i].F>>a[i].S,divn.insert(a[i].F),divn.insert(a[i].S);
  genDiv(a[0].F);genDiv(a[0].S);
  FOR(i,0,n)crop(i);
  if(divn.empty())OUT(-1);
  else OUT(*divn.begin());
}