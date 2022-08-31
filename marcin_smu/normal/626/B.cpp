#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif

int n;
string z;
char lacz(char a,char b){
  if(a == b)return a;
  return 'R' + 'B' + 'G' - a - b;
}
char get_random(vector<char>& s){
  int i = rand() % SZ(s);
  char res = s[i];
  swap(s[i],s.back());
  s.pop_back();
  return res;
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  
  cin >> n >> z;
  set<char> res;
  R(_,10000){
    vector<char> s(ALL(z));
    while(SZ(s)!=1){
      char a = get_random(s);
      char b = get_random(s);
      s.PB(lacz(a,b));
    }
    res.insert(s[0]);
  }
  for(auto z:res){
    cout << z;
  }
  cout << endl;
}