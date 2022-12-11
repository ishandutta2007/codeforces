#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  int n;
  cin >> n;
  vector<lli> a(n);
  for (lli& i : a)
    cin >> i;
  int f = find(a.begin(), a.end(), -1) - a.begin();
  vector<lli> v(f, 0);
  v.insert(v.end(), a.begin()+f+1, a.end());
  priority_queue<lli, vector<lli>, greater<lli>> pq;
  pq.push(v[n-2]);
  lli ans=0;
  for (int l=n/2; l>1; l/=2) {
    ans += pq.top(); pq.pop();
    for (int i=l-2; i<2*l-2; ++i)
      pq.push(v[i]);
  }
  ans += pq.top();
  cout << ans << endl;
}