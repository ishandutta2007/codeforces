#include <iostream>
#include <queue>
using namespace std;
#define ll long long
const ll mn=1e6+4;
ll vrow[mn],vcol[mn];

int main()
{
  ll n, m, k, p;
  cin >> n;
  cin >> m;
  cin >> k;
  cin >> p;
  ll **a = new ll*[n];
  for (ll i = 0; i < n; i++) {
    a[i] = new ll[m];
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  ll *r = new ll[n];
  ll *c = new ll[m];
  for (ll i = 0; i < n; i++) {
    r[i] = 0;
  }
  for (ll j = 0; j < m; j++) {
    c[j] = 0;
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      r[i] += a[i][j];
      c[j] += a[i][j];
    }
  }
  priority_queue<ll> row;
  priority_queue<ll> col;
  for (ll i = 0; i < n; i++) {
    row.push(r[i]);
  }
  for (ll j = 0; j < m; j++) {
    col.push(c[j]);
  }
  ll sum=0;
  for (ll x=1;x<=k;x++) {
    ll best_row=row.top(); row.pop();
    sum+=best_row;
    best_row-=p*m;
    row.push(best_row);
    vrow[x]=sum;
  }
  sum=0;
  for (ll x=1;x<=k;x++) {
    ll best_col=col.top(); col.pop();
    sum+=best_col;
    best_col-=p*n;
    col.push(best_col);
    vcol[x]=sum;
  }
  ll pleasure=LLONG_MIN;
  for (ll r=0;r<=k;r++) {
    ll c=k-r;
    ll cand=vrow[r]+vcol[c]-r*c*p;
    pleasure=max(pleasure,cand);
  }
  cout << pleasure << endl;
}