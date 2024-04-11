#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


#define MAXX (1<<20)
int n,dp[2*MAXX],sum[2*MAXX],MAX=1,pol=-1,t2[MAXX],odp[MAXX];
bool cz[MAXX];
PII t[MAXX];
LL wyn;
void licz(int i){
 dp[i]=min(dp[i*2],sum[i*2]+dp[i*2+1]);
 sum[i]=sum[i*2]+sum[i*2+1];
}
void add(int i,int il){
 i+=MAX;
 dp[i]+=il;
 sum[i]+=il;
 do{
  i/=2;
  licz(i);
 }while(i>1);
}
main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  while(MAX<=n)MAX*=2;
  R(i,n){
    cin >> t2[i];
    t2[i] -= i;
    t[i].FI = t2[i];
    t[i].SE = i;
  }
 sort(t,t+n);
 for(int i=0;i<=n;i++){
  dp[i+MAX]=1;
  sum[i+MAX]=1;
 }
 for(int i=MAX-1;i;i--)licz(i);
 for(int i=0;i<n;i++){
  if(pol<t[i].SE){
   cz[t[i].SE]=1;                
   add(t[i].SE,-2);
  }
  while(dp[1]<=0){
   int il=0;
   do{
    pol++;
    odp[pol]=t[i].FI;
    wyn+=abs(odp[pol]-t2[pol]);
    if(cz[pol])
    il--;
    else
    il++;
   }while(il!=dp[1]);
   add(0,2-dp[1]);
   add(pol+1,-2);
  }
 }
 cout << wyn << "\n";
}