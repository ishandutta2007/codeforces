#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n, ps[2];
string s;
map<char,int> cnt;

bool can(int i){
  int t = n / i;
  if(t%2){
    return ps[1]<= i && (ps[1]%2==i%2);
  }else{
    return ps[1]==0;
  }
}
vector<char> vs[2];
void gen(int i){
  int t = n/i;
  vector<string> ws;
  if(t%2){
    int needed = i - ps[1];
    vector<char> tmp;
    for(auto c : vs[1]){
      tmp.pb(c); cnt[c]--;
      if(cnt[c]==0)cnt.erase(c);
    }
    while(needed){
      pair<char, int> asd= *cnt.begin(); cnt.erase(asd.first);
      tmp.pb(asd.first);
      tmp.pb(asd.first);
      asd.second-=2; needed-=2;
      if(asd.second)cnt[asd.first]=asd.second;
    }
    for(auto p : cnt){
      fore(x,0,p.second/2){
        if(ws.empty() || SZ(ws.back())==t/2)
          ws.pb("");
        ws.back() += p.first; 
      }
    }
    if(ws.empty()){fore(x,0,i)ws.pb("");}
    fore(x,0,i){
      string wsr=ws[x]; reverse(wsr.begin(),wsr.end());
      ws[x]+=tmp[x]; ws[x]+=wsr;
      cout << ws[x] << " \n"[x+1==i];
    }
  }else{
    for(auto p : cnt){
      fore(x,0,p.second/2){
        if(ws.empty() || SZ(ws.back())==t/2)
          ws.pb("");
        ws.back() += p.first; 
      }
    }
    fore(x,0,i){
      string wsr=ws[x]; reverse(wsr.begin(),wsr.end());
      ws[x]=ws[x]+wsr;
      cout << ws[x] << " \n"[x+1==i];
    }
  }
}
int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s;
  fore(x,0,n)cnt[s[x]]++;
  for(auto p : cnt)ps[p.second%2]++, vs[p.second%2].pb(p.first);

  int ans=n;
  for(int x=1; x*x<=n; x++){
    if(n%x!=0)continue;
    if(can(x))ans=min(ans,x);
    if(can(n/x))ans=min(ans,n/x);
  }

  cout << ans << "\n";
  gen(ans);
}