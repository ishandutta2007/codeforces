#include <bits/stdc++.h>
using namespace std;
bool compare(string a , string b) {
    int i;
    if (a.size()!=b.size()) {
        return false;
    }
    else {
        for ( i = 0 ; i < a.size(); i++) {
            if (a[i]!=b[i]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{ int n;
  cin>>n;
  int i;
  string s[n];
  int a[n];
  int j;
  vector <pair <int, string >> t;
  for ( i = 0 ; i < n ; i ++) {
    cin>>s[i];
    cin>>a[i];
    bool fin=false;
    for ( j = 0; j < t.size() ; j++) {
        if (s[i]==t[j].second) {
            t[j].first+=a[i];
            fin=true;
            break;
        }
    }
    if (fin==false) {
        auto r = make_pair(a[i],s[i]);
        t.push_back(r);
    }
  }
  vector < pair < int, int > > l( t.size());
  for ( j = 0; j < t.size(); j++) {
  l[j].first=0;
  for ( i = 0 ; i < n; i++) {
    if (t[j].second==s[i]) {
       l[j].first+=a[i];
       if ( l[j].first >= t[j]. first) {
         l[j].second = i;
         break;
       }
    }
  }
}
  int m = t[0].first;
  int z = l[0].second;
  int k = 0;
  for ( i = 1; i < t.size(); i++) {
    if ( t[i].first > m || (t[i].first==m && l[i].second < z)) {
        m = t[i].first; z = l[i].second; k = i;
        }
  }
   cout<<t[k].second;
    return 0;
}