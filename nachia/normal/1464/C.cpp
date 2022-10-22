
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const ll INF = 1001001001001001001;
const string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";

void testcase(){
  int N;
  ll Val;
  cin >> N >> Val;
  string S;
  cin >> S;
  vector<ll> cnt(26,0);
  for(int i=0; i<N-2; i++) cnt[lower_alphabet.find(S[i])]++;
  Val -= 1ll << lower_alphabet.find(S[N-1]);
  Val += 1ll << lower_alphabet.find(S[N-2]);

  ll lVal = 0, rVal = 0;
  for(int d=0; d<26; d++){
    if(lVal == rVal){
      ll parityMakeableVal = (cnt[d] & 1) ^ (lVal & 1);
      if((Val & 1) != parityMakeableVal){ cout << "No\n"; return; }
    }
    lVal -= cnt[d];
    rVal += cnt[d];
    if(Val & 1){ Val--; lVal--; rVal--; }
    if(lVal & 1) lVal++;
    if(rVal & 1) rVal--;
    lVal /= 2;
    rVal /= 2;
    Val /= 2;
  }

  if(Val < lVal || rVal < Val){ cout << "No\n"; return; }
  cout << "Yes\n";
}

int main(){
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;