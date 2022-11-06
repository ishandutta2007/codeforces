#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

int main() {FIN;
  int n;cin>>n;
  fore(i,0,n) {
    string s,t;cin>>s>>t;
    map<char,int>m;
    for(char c:t)m[c]++;
    string res;
    for(int i=SZ(s)-1;i>=0;i--) {
      if(m[s[i]])m[s[i]]--,res+=s[i];
    }
    reverse(ALL(res));
    if(res==t)cout<<"YES\n";
    else cout<<"NO\n";
  }
}