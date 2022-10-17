#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const ll MAX = (1LL<<32) - 1;
int n,cnt;
vector<ll> st;
char s[5];
ll ans;

void overflow() {
  puts("OVERFLOW!!!");
  exit(0);
}

int main() {
  scanf("%d",&n);
  st.push_back(1);
  REP(i,n) {
    scanf("%s",s);
    if (s[0] == 'a') {
      if (st.back() == -1) overflow();
      ans += st.back();
      if (ans > MAX) overflow();
    } else if (s[0] == 'f') {
      scanf("%d",&cnt);
      ll nval = st.back() * cnt;
      if (st.back() == -1 || nval > MAX) nval = -1;
      st.push_back(nval);
    } else {
      st.pop_back();
    }
  }
  printf("%lld\n", ans);
}