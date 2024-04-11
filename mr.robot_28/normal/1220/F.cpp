#include <bits/stdc++.h>
#define SZ (1<<19)
const int inf=1e9;
using namespace std;
int n;
 
int _a[202020];
vector<int> a;
vector<int> rv;
 
int sp[SZ];
 
int mn(int a, int b) { a+=SZ/2; b+=SZ/2;
  int r=sp[a];
  while (a<b) {
    if (a&1) r=min(r, sp[a++]);
    if (~b&1)r=min(r, sp[b--]);
    a/=2;b/=2;
  }if (a==b) r=min(r, sp[a]);
  return r;
}
 
 
int d(int a, int b) {
//   cout << "d(" << a << ", " << b << ")" << endl;
  if (a>b) return 0;
  if (a==b) return 1;
  int m=mn(a, b);
  int mi=rv[m];
  int rv = max(d(a, mi-1), d(mi+1, b))+1;
//   cout << "=" << rv << endl;
  return rv;
}
 
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> n;
  a.resize(n);
  rv.resize(n+1);
  int oj=0;
  for (int i=0;i<n;++i) {
    cin >> _a[i];
    if (_a[i]==1) oj=i;
  }
  int j=oj;
  for (int i=0;i<n;++i) {
    a[i]=_a[j];
    rv[a[i]]=i;
    
    ++j;
    if (j==n) j=0;
  }
  for (int i=n-1;i>=0;--i) {
    sp[i+SZ/2]=a[i];
  }
  for (int i=n;i<SZ/2;++i) sp[i+SZ/2]=inf;
  for (int i=SZ/2-1;i;--i) {
    sp[i]=min(sp[2*i], sp[2*i+1]);
  }
  
  int a=1;
  int b=n-1;
  while (a<b) {
    int m=(a+b)/2;
    int d1=d(1, m);
    int d2=d(m+1, n-1);
    if (d1<d2)  a=m+1;
    else b=m;
  }
//   for (int i=1;i<n;++i) {
//     cout << "d(" << 1 << ", " << i << ")=" << d(1,i) << ", d(" << i+1 << ", " << n-1 << ")=" << d(i+1, n-1) << "\n"; 
//   }
//   cout << a << endl;
  int l=max(d(1, a-1), d(a, n-1))+1;
  int r=max(d(1, a), d(a+1, n-1))+1;
  if (l < r) {
//     cout << 1 << endl;
//     cout << a-1 << endl;
    int v=oj+a;
    v%=n;
    cout << l << " " << v << "\n";
  } else {
//     cout << 2 << endl;
//     cout << a << endl;
    int v=oj+1+a;
    v%=n;
    cout << r << " " << v << "\n";
  }
  
}