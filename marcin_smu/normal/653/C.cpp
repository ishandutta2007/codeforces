#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LD long double
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto& tt : V) { os << tt << ","; }
  os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

#define MAX 200001
int n;
int t[MAX];
int il;
int zle;
void dod(int a,int x){
  if(t[a] == t[a+1]) zle += x;
  if((t[a] < t[a+1]) ^ (a&1))
    il += x;
}

set<PII> x;
int res;
void spr2(int a,int b){
  if(a == b)return;
  if(a > b)swap(a,b);
  if(!x.insert({a,b}).SE)return;
  
  int zle2=zle,il2=il;
  if(a)dod(a-1,-1);
  dod(a,-1);
  if(b!=a+1)dod(b-1,-1);
  dod(b,-1);
  
  swap(t[a],t[b]);
  
  if(a)dod(a-1,1);
  dod(a,1);
  if(b!=a+1)dod(b-1,1);
  dod(b,1);
  
  debug(a,b,zle,il);
  if(zle == 0 && il == n-1)
    res++;
  
  swap(t[a],t[b]);
  zle = zle2;
  il = il2;
}

void spr(int i){
  R(j,n)spr2(i,j);
}

#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  cin >> n;
  R(i,n)cin >> t[i];
  if(n == 2){
    cout << (t[0] != t[1]) << "\n";
    return 0;
  }
  R(i,n-1)dod(i,1);
  debug(il,zle);
  R(i,n-2){
    if(t[i] == t[i+1] || t[i+1] == t[i+2] || 
       ((t[i] < t[i+1]) ^ (t[i+1] > t[i+2])) ){
         spr(i);
         spr(i+1);
         spr(i+2);
         cout << res << endl;
         return 0;
      }
  }
  assert(0);
}