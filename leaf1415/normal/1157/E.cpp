#include <iostream>
#include <set>

using namespace std;

int n;
int a[200005], b[200005];
multiset<int> S;

int get(int x)
{
  auto p = S.lower_bound(x);
  if(p == S.end()) p = S.begin();
  int ret = *p;
  S.erase(p);
  return ret;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++) S.insert(b[i]);

  for(int i = 1; i <= n; i++){
    int x = get((n-a[i])%n);
    cout << (a[i]+x)%n << " ";
  }
  cout << endl;

  return 0;
}