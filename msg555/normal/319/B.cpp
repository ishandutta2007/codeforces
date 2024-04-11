#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int A[100010];

int main() {
  int N; cin >> N;

  set<int> st;
  set<int> fst;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    st.insert(i);
    fst.insert(i);
  }

  int result = -1;
  while(!st.empty()) {
    result++;

    set<int> nst;
    set<int>::iterator it, jt;

    for(typeof(st.end()) it = st.end(); it-- != st.begin(); ) {
      jt = fst.find(*it);
      if(jt == fst.end()) continue;
      ++jt;

      if(jt != fst.end() && A[*jt] < A[*it]) {
        fst.erase(*jt);
        nst.insert(*it);
      }
    }

    st.swap(nst);
  }

  cout << result << endl;
  return 0;
}