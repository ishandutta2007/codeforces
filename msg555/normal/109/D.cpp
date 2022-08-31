#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> V;

void gen(int dig) {
  for(int i = 1; i <= dig; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int num = 0;
      for(int k = 0; k < i; k++) {
        num *= 10;
        num += (j & 1 << k) ? 7 : 4;
      }
      V.push_back(num);
    }
  }
  sort(V.begin(), V.end());
}

int L0, L1, H0, H1, K;

int A[100000];

int main() {
  gen(9);

  int pivot = -1;

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(binary_search(V.begin(), V.end(), A[i])) pivot = i;
  }

  if(N == 1 || pivot == -1) {
    bool ok = true;
    for(int i = 1; ok && i < N; i++) ok = A[i - 1] <= A[i];
    cout << (ok ? 0 : -1) << endl;
    return 0;
  }

  set<pair<int, int> > st;
  for(int i = 0; i < N; i++) {
    if(i != pivot) {
      st.insert(make_pair(A[i], i));
    }
  }

  vector<pair<int, int> > swps;

  bool jmp = false;
  for(int i = 0; !st.empty(); i++) {
    if(!jmp && st.begin()->first >= A[pivot]) {
      jmp = true;
      i++;
    }

    if(pivot != i) {
      swps.push_back(make_pair(pivot, i));
      st.erase(make_pair(A[i], i));
      st.insert(make_pair(A[i], pivot));
      swap(A[pivot], A[i]);
      pivot = i;
    }

    int ind = st.begin()->second;
    st.erase(st.begin());

    swps.push_back(make_pair(pivot, ind));
    swap(A[pivot], A[ind]);
    pivot = ind;
  }

  bool ok = true;
  for(int i = 1; ok && i < N; i++) ok = A[i - 1] <= A[i];
  if(!ok) cout << "FAIL" << endl;

  cout << swps.size() << endl;
  for(int i = 0; i < swps.size(); i++) {
    cout << swps[i].first + 1 << " " << swps[i].second + 1 << endl;
  }

  return 0;
}