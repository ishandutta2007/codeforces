#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

int C[3010][3010];
int EV[3010][3010];
int EH[3010][3010];

int R1[100010];
int C1[100010];
int R2[100010];
int C2[100010];

bool byc1(int i, int j) {
  return C1[i] < C1[j];
}

bool byc2(int i, int j) {
  return C2[i] < C2[j];
}

int query(int A[][3010], int r1, int c1, int r2, int c2) {
  return A[r2][c2] - A[r1][c2] - A[r2][c1] + A[r1][c1];
}

int get_wing(int r, int c, int dr, int dc) {
  int lo = 0;
  int hi = 3000;
  while(lo < hi) {
    int md = (lo + hi + 1) / 2;

    int r1 = r;
    int c1 = c;
    int r2 = r + md * dr + (dr ? dr : 1);
    int c2 = c + md * dc + (dc ? dc : 1);
    if(r2 < 0) r2 = 0;
    if(r2 > 3000) r2 = 3000;
    if(c2 < 0) c2 = 0;
    if(c2 > 3000) c2 = 3000;
    if(r2 < r1) swap(r1, r2);
    if(c2 < c1) swap(c1, c2);

    if(query(dr ? EV : EH, r1, c1, r2, c2) == 0) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }
  return lo + 1;
}

int main() {
  int N; cin >> N;
  map<int, vector<int> > TL, BR;

  for(int i = 0; i < N; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    TL[r1 - c1].push_back(i);
    BR[r2 - c2].push_back(i);
    R1[i] = r1; C1[i] = c1;
    R2[i] = r2; C2[i] = c2;

    for(int r = r1; r < r2; r++) {
      for(int c = c1; c < c2; c++) {
        C[r + 1][c + 1]++;
      }
    }
    for(int r = r1; r < r2; r++) {
      for(int c = c1 + 1; c < c2; c++) {
        EV[r + 1][c + 1]++;
      }
    }
    for(int r = r1 + 1; r < r2; r++) {
      for(int c = c1; c < c2; c++) {
        EH[r + 1][c + 1]++;
      }
    }
  }
  for(int r = 1; r <= 3000; r++) {
    for(int c = 1; c <= 3000; c++) {
      C[r][c] += C[r - 1][c] + C[r][c - 1] - C[r - 1][c - 1];
      EV[r][c] += EV[r - 1][c] + EV[r][c - 1] - EV[r - 1][c - 1];
      EH[r][c] += EH[r - 1][c] + EH[r][c - 1] - EH[r - 1][c - 1];
    }
  }

  for(typeof(TL.begin()) it = TL.begin(); it != TL.end(); ++it) {
    vector<int>& vtl = it->second;
    vector<int>& vbr = BR[it->first];
    if(vbr.empty()) continue;

    sort(vtl.begin(), vtl.end(), byc1);
    sort(vbr.begin(), vbr.end(), byc2);

    int i = vtl.size();
    int j = vbr.size();

    deque<pair<int, int> > dq;
    while(i > 0) {
      if(j == 0 || C1[vtl[i - 1]] >= C2[vbr[j - 1]]) {
        int idx = vtl[--i];

        int wings = min(get_wing(R1[idx], C1[idx], 1, 0),
                        get_wing(R1[idx], C1[idx], 0, 1));

        while(!dq.empty()) {
          int sz = C2[dq.back().first] - C1[idx];
          if(query(C, R1[idx], C1[idx], R1[idx] + sz, C1[idx] + sz) !=
                    sz * sz) {
            dq.pop_back();
          } else {
            break;
          }
        }
        while(!dq.empty()) {
          int sz = C2[dq[0].first] - C1[idx];
          if(dq[0].second < sz) {
            dq.pop_front();
          } else {
            break;
          }
        }
        if(!dq.empty()) {
          int sz = C2[dq[0].first] - C1[idx];
          if(wings >= sz) {
            int r1 = R1[idx];
            int c1 = C1[idx];
            int r2 = R2[dq[0].first];
            int c2 = C2[dq[0].first];

            vector<int> result;
            for(int i = 0; i < N; i++) {
              if(r1 <= R1[i] && R2[i] <= r2 &&
                 c1 <= C1[i] && C2[i] <= c2) {
                result.push_back(i);
              }
            }
            cout << "YES " << result.size() << endl;
            for(int i = 0; i < result.size(); i++) {
              if(i) cout << ' ';
              cout << result[i] + 1;
            }
            cout << endl;
            return 0;
          }
        }
      } else {
        int idx = vbr[--j];
        int wings = min(get_wing(R2[idx], C2[idx], -1, 0),
                        get_wing(R2[idx], C2[idx], 0, -1));
        dq.push_front(make_pair(idx, wings));
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}