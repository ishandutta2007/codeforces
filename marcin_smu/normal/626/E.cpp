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

#define MAX 200010

int sp[MAX];
int t[MAX];
int n;
struct wyn{
  int il,sum,med;
  wyn(int me,int ill){
    il = ill * 2 + 1;
    med = t[me];
    sum = sp[n] - sp[n-ill] + sp[me+1] - sp[me - ill];
  }
  wyn(){};
};
bool cmp(wyn a,wyn b){
  return a.sum * b.il - a.med * a.il * b.il < b.sum * a.il - b.med * a.il * b.il;
}
wyn naj;
void akwyn(wyn pom){
  if(cmp(naj,pom))
    naj = pom;
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n;
  R(i,n){
    cin >> t[i];
  }
  sort(t,t+n);
  R(i,n){
    sp[i+1] = sp[i] + t[i];
  }
  
  naj.il = 1;
  naj.sum = t[0];
  naj.med = t[0];
  R(i,n){
    int po = 0,ko = min(i,n-i-1);
    while(po + 1 < ko){
      int m1 = (po+ko)/2;
      int m2 = m1 + 1;
      wyn m1w(i,m1);
      wyn m2w(i,m2);
      if(cmp(m1w, m2w)){
        po = m2;
      }else{
        ko = m1;
      }
    }
    wyn pw(i,po);
    akwyn(pw);
    wyn kw(i,ko);
    akwyn(kw);
  }

  debug(naj.il, naj.sum, naj.med);
  
  cout << naj.il << endl;
  int pom = n-naj.il/2-1;
  while(t[pom] != naj.med)pom--;
  R(i,naj.il/2+1){
    cout << t[pom-i] << " ";
  }
  R(i,naj.il/2){
    cout << t[n-i-1] << " ";
  }
  cout << "\n";
  
}