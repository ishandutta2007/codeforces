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

int n;
set<string> ss;

string apply(string s){
  bool can=1;
  while(can){
    can=0;
    fore(x,0,SZ(s))
      if(s[x]=='u'){
        s=s.substr(0,x)+"oo"+s.substr(x+1);
        can=1;
        break;
      }
      
    if(!can){
        fore(x,0,SZ(s)-1)if(s[x]=='k'&&s[x+1]=='h'){
            s=s.substr(0,x)+"h"+s.substr(x+2);
            can=1;break;
          }
    }
  }
  return s;
}

int main(){
  cin >> n;
  fore(x,0,n){
    string s; cin >> s;
    ss.insert(apply(s));
  }
  cout << SZ(ss) << "\n";
	return 0;
}