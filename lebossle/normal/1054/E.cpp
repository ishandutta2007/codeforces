#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n, m;

vector<pair<ii, ii> > solve(vector<vector<string> > inp) {
  stringstream ss;

  for (int i=0; i<inp[0][0].size(); ++i)
    ss << 1 << ' ' << 1 << ' ' << n << ' ' << 1 << '\n';
  inp[n-1][0] = inp[0][0]+inp[n-1][0];
  inp[0][0]="";

  for (int i=0; i<inp[n-1][m-1].size(); ++i)
    ss << n << ' ' << m << ' ' << 1 << ' ' << m << '\n';
  inp[0][m-1] = inp[n-1][m-1]+inp[0][m-1];
  inp[n-1][m-1]="";

  vector<int> acum0(n, 0), acum1(n, 0);
  for (int i=0; i<n; ++i)
    for (int j=1; j<m-1; ++j)
      for (int k=inp[i][j].size()-1; k>=0; --k)
        if (inp[i][j][k] == '0') {
          ss << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << 1 << '\n';
          acum0[i]++;
        } else {
          ss << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << m << '\n';
          acum1[i]++;
        }

  for (int i=1; i<n; ++i)
    for (int k=inp[i][0].size()-1; k>=0; --k)
      if (inp[i][0][k] == '0') {
        ss << i+1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
      } else {
        ss << i+1 << ' ' << 1 << ' ' << i+1 << ' ' << m << '\n';
        acum1[i]++;
      }
  for (int i=0; i<n-1; ++i)
    for (int k=inp[i][m-1].size()-1; k>=0; --k)
      if (inp[i][m-1][k] == '0') {
        ss << i+1 << ' ' << m << ' ' << i+1 << ' ' << 1 << '\n';
        acum0[i]++;
      } else {
        ss << i+1 << ' ' << m << ' ' << n << ' ' << m << '\n';
      }

  for (int i=1; i<n; ++i)
    for (int k=0; k<acum0[i]; ++k)
      ss << i+1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
  for (int i=0; i<n-1; ++i)
    for (int k=0; k<acum1[i]; ++k)
      ss << i+1 << ' ' << m << ' ' << n << ' ' << m << '\n';

  vector<pair<ii, ii> > sol;
  int x1, x2, x3, x4;
  while (ss >> x1 >> x2 >> x3 >> x4) {
    sol.push_back(make_pair(ii(x1, x2), ii(x3, x4)));
  }
  return sol;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<vector<string> > inp(n, vector<string>(m));
  vector<vector<string> > out(n, vector<string>(m));
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      cin >> inp[i][j];
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j) {
      cin >> out[i][j];
      reverse(out[i][j].begin(), out[i][j].end());
    }
  vector<pair<ii, ii> > sinp = solve(inp), sout = solve(out);
  cout << sinp.size()+sout.size() << endl;
  for (auto p : sinp)
    cout << p.first.first << ' ' << p.first.second << ' ' << p.second.first << ' ' << p.second.second << '\n';
  for (int i=sout.size()-1; i>=0; --i) {
    auto p = sout[i];
    cout << p.second.first << ' ' << p.second.second << ' ' << p.first.first << ' ' << p.first.second << '\n';
  }
}