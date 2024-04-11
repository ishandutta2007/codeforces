#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

long long A[100010];
long long VAL[100010];
long long AVAL[100010];
pair<pair<int, int>, vector<int> > S[100010];
vector<int> RA[100010];

#define MXSM 200 

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 0; i < M; i++) {
    cin >> S[i].first.first;
    S[i].first.second = i;
    S[i].second.resize(S[i].first.first);
    for(int j = 0; j < S[i].second.size(); j++) {
      cin >> S[i].second[j];
      S[i].second[j]--;
    }
  }

  sort(S, S + M);
  reverse(S, S + M);

  vector<int> kmp(M, -1);
  for(int i = 0; i < M; i++) {
    kmp[S[i].first.second] = i;
  }

  int SM = min(MXSM, M);
  for(int i = 0; i < SM; i++) {
    for(int j = 0; j < S[i].second.size(); j++) {
      RA[S[i].second[j]].push_back(i);
    }
  }

  vector<vector<int> > pcnt(M, vector<int>(SM, 0));
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < S[i].second.size(); j++) {
      int ind = S[i].second[j];

      VAL[i] += A[ind];
      for(int k = 0; k < RA[ind].size(); k++) {
        ++pcnt[i][RA[ind][k]];
      }
    }
  }
  memset(A, 0, sizeof(A));

  for(int i = 0; i < Q; i++) {
    char cmd; int k;
    cin >> cmd >> k; k--;
    k = kmp[k];

    if (cmd == '+') {
      long long x; cin >> x;
      for(int j = 0; j < SM; j++) {
        VAL[j] += x * pcnt[k][j];
      }
      if(k < SM) {
        AVAL[k] += x;
      } else for(int j = 0; j < S[k].second.size(); j++) {
        A[S[k].second[j]] += x;
      }
    } else {
      if (k < SM) {
        cout << VAL[k] << '\n';
      } else {
        long long val = VAL[k];
        for(int j = 0; j < SM; j++) {
          val += AVAL[j] * pcnt[k][j];
        }
        for(int j = 0; j < S[k].second.size(); j++) {
          val += A[S[k].second[j]];
        }
        cout << val << '\n';
      }
    }
  }

  return 0;
}