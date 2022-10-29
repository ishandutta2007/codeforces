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

const int M=1000;
int n, m;
string s;
bool A[26];
bool B[M][26];

int main(){
  cin >> n >> s;
  fore(x,0,SZ(s))if(s[x]!='*')A[s[x]-'a']=1;
  cin >> m;
  vector<string> words;
  fore(x,0,m){
    string tmp; cin >> tmp;
    bool can=1;
    fore(y,0,SZ(s))
      if(s[y]=='*' && A[tmp[y]-'a'])can=0;
      else if(s[y]!='*' && s[y]!=tmp[y])can=0;
    if(can)words.pb(tmp);
  }
  fore(x,0,SZ(words)){
    fore(y,0,SZ(s))if(s[y]=='*')B[x][words[x][y]-'a']=1;
  }
  
  int cnt=0;
  fore(x,0,26){
    int tmp=0;
    fore(y,0,SZ(words)){
      tmp += B[y][x]; 
    }
    cnt+=(tmp==SZ(words));
  }
  cout << cnt << "\n";
	return 0;
}