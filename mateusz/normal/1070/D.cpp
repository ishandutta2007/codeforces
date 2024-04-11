#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - )
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size()
#define VI vector<int>
#define PII pair<int,int>

int t[1000006],n,k,wynik;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n + 1;i++) {
        if(i <= n)
      cin>>t[i];
        wynik+=(t[i-1]/k);
        t[i-1]%=k;
        if(t[i-1]!=0) {
            wynik++;
            t[i]-=(k-t[i-1]);
            t[i-1]=0;
            t[i]=max(t[i],0ll);
        }
    }
    cout<<wynik<<endl;
}