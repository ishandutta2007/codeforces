#include <bits/stdc++.h>

using namespace std;

int n, k;
multiset<int> st;
set<int> unique_st;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k+1; i++) {
    cout << "? ";
    for (int j = 1; j <= k+1; j++)
      if (j != i)
        cout << j << ' ';
    cout << endl;

    int pos, val;
    cin >> pos >> val;
    st.insert(val);
    unique_st.insert(val);
  }

  assert(unique_st.size() <= 2);
  int cnt = st.count(*st.rbegin());
  cout << "! " << cnt << endl;
}