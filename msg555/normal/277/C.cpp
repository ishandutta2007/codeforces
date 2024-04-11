#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  int res = (N % 2 ? 0 : M) ^ (M % 2 ? 0 : N);

  map<int, vector<pair<int, int> > > vcut, hcut;
  map<int, vector<pair<int, int> > > vsec, hsec;
  map<int, int> vlen, hlen;
  for(int i = 0; i < K; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
      if(y2 < y1) swap(y1, y2);
      vcut[x1].push_back(make_pair(y1, y2));
    } else {
      if(x2 < x1) swap(x1, x2);
      hcut[y1].push_back(make_pair(x1, x2));
    }
  }

  for(typeof(vcut.begin()) it = vcut.begin(); it != vcut.end(); it++) {
    vector<pair<int, int> >& A = it->second;

    int& ln = vlen[it->first];
    vector<pair<int, int> >& B = vsec[it->first];

    sort(A.begin(), A.end());
    ln = A[0].first;
    int prr = A[0].first;
    int mxr = A[0].second;
    for(int i = 0; i < A.size(); i++) {
      if(mxr < A[i].first) {
        B.push_back(make_pair(prr, mxr));
        prr = A[i].first;
        ln += A[i].first - mxr;
      }
      mxr = max(mxr, A[i].second);
    }
    B.push_back(make_pair(prr, mxr));

    ln += M - mxr;
    res ^= M ^ ln;
  }
  for(typeof(hcut.begin()) it = hcut.begin(); it != hcut.end(); it++) {
    vector<pair<int, int> >& A = it->second;

    int& ln = hlen[it->first];
    vector<pair<int, int> >& B = hsec[it->first];

    sort(A.begin(), A.end());
    ln = A[0].first;
    int prr = A[0].first;
    int mxr = A[0].second;
    for(int i = 0; i < A.size(); i++) {
      if(mxr < A[i].first) {
        B.push_back(make_pair(prr, mxr));
        prr = A[i].first;
        ln += A[i].first - mxr;
      }
      mxr = max(mxr, A[i].second);
    }
    B.push_back(make_pair(prr, mxr));

    ln += N - mxr;
    res ^= N ^ ln;
  }

  if(res == 0) {
    cout << "SECOND" << endl;
  } else {
    cout << "FIRST" << endl;

    bool found = false;
    for(typeof(vlen.begin()) it = vlen.begin();
        !found && it != vlen.end(); it++) {
      if((it->second ^ res) < it->second) {
        vector<pair<int, int> > B = vsec[it->first];

        int nlen = it->second ^ res;
        for(int i = 0; i < B.size() && nlen > B[i].first; i++) {
          nlen += B[i].second - B[i].first;
        }
        cout << it->first << " " << nlen << " " <<
                it->first << ' ' << M << endl;

        found = true;
      }
    }
    for(typeof(hlen.begin()) it = hlen.begin();
        !found && it != hlen.end(); it++) {
      if((it->second ^ res) < it->second) {
        vector<pair<int, int> > B = hsec[it->first];

        int nlen = it->second ^ res;
        for(int i = 0; i < B.size() && nlen > B[i].first; i++) {
          nlen += B[i].second - B[i].first;
        }
        cout << nlen << " " << it->first << " " <<
                N << " " << it->first << endl;

        found = true;
      }
    }
    if(!found && (M ^ res) < M && vlen.size() + 1 < N) {
      int xc;
      for(xc = 1; vlen.find(xc) != vlen.end(); xc++);
      cout << xc << " " << (M ^ res) << " " << xc << " " << M << endl;
    } else if(!found) {
      int yc;
      for(yc = 1; hlen.find(yc) != hlen.end(); yc++);
      cout << (N ^ res) << " " << yc << " " << N << " " << yc << endl;
    }
  }
}