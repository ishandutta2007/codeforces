#include <bits/stdc++.h>
using namespace std;
bool cmp( pair<int,int> a, pair<int,int> b) {
    return (a.first < b.first);
}
bool cmp1( pair < int, int > a, pair <int ,int > b) {
   return (a.first > b.first);
 }
int main()
{ int m;
  cin>>m;
  vector< pair <int, int > > a;
  vector< pair <int, int > > b;
  int i;
  int x;
  for ( i = 0; i < m; i++) {
    cin>>x;
    auto t = make_pair(x,i);
    a.push_back(t);
  }
  for ( i =0 ; i < m; i++) {
    cin>>x;
    auto t = make_pair(x,i);
    b.push_back(t);
  }
  int c[m];
  sort(a.begin(),a.end(),cmp);
  sort(b.begin(),b.end(),cmp1);
  for ( i = 0; i < m; i++) {
    c[b[i].second]=a[i].first;
  }
  for ( i = 0 ; i < m ;i++) {
    cout<<c[i]<<" ";
  }
    return 0;
}