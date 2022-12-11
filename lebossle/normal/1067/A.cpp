#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 998244353;

int main() {
  lli n;
  cin >> n;
  vector<lli> inp(n);
  for (lli i=0; i<n; ++i)
    cin >> inp[i];
  vector<vector<lli> > dpValid(n, vector<lli>(201, 0)), dpWait(n, vector<lli>(201, 0));
  for (lli i=0; i<n; ++i) {
    lli totalValid = 0, totalWait = 0;
    if (i == 0) {
      totalValid = 1;
    } else {
      for (lli v=1; v<=200; ++v) {
        totalValid = (totalValid + dpValid[i-1][v])%MOD;
        totalWait = (totalWait + dpWait[i-1][v])%MOD;
      }
    }
    //cout << totalValid << ' ' << totalWait << endl;
    lli acumValid = 0, acumWait = 0;
    for (lli v=1; v<=200; ++v) {
      if (inp[i] == v || inp[i] == -1) {
        if (i == 0) {
          dpWait[i][v] = 1;
          dpValid[i][v] = 0;
        } else {
          dpValid[i][v] = (totalValid-acumValid+dpWait[i-1][v]+MOD)%MOD;
          dpWait[i][v] = (acumWait+acumValid)%MOD;
        }
      } else {
        dpValid[i][v] = 0;
        dpWait[i][v] = 0;
      }
      //cout << dpValid[i][v] << ',' << dpWait[i][v] << ' ';
      if (i>0) {
        acumValid = (acumValid + dpValid[i-1][v])%MOD;
        acumWait = (acumWait + dpWait[i-1][v])%MOD;
      }
    }
    //cout << endl;
  }
  lli ans=0;
  for (lli v=1; v<=200; ++v)
    ans = (ans + dpValid.back()[v])%MOD;
  cout << ans << endl;
}