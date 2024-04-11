#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int sum = 0;
  vector<pair<string, pair<int, int> > > A, B, C;
  for(int i = 0; i < N; i++) {
    string name, type; cin >> name >> type;
    int atk, def, orb, sz; cin >> atk >> def >> orb >> sz;
    if(type == "weapon") {
      A.push_back(make_pair(name, make_pair(atk, sz)));
    } else if(type == "armor") {
      B.push_back(make_pair(name, make_pair(def, sz)));
    } else {
      C.push_back(make_pair(name, make_pair(orb, sz)));
    }
    sum += sz;
  }
  int M; cin >> M;
  map<string, vector<string> > mp;

  set<string> names;
  vector<pair<int, string> > EA, EB, EC;
  for(int i = 0; i < M; i++) {
    string name, type, home; int bonus;
    cin >> name >> type >> bonus >> home;
    mp[home].push_back(name);
    names.insert(name);

    if(type == "gladiator") {
      if(M == sum) {
        for(int i = 0; i < A.size(); i++) if(A[i].first == home) {
          A[i].second.first += bonus;
        }
      } else {
        EA.push_back(make_pair(bonus, name));
      }
    } else if(type == "sentry") {
      if(M == sum) {
        for(int i = 0; i < B.size(); i++) if(B[i].first == home) {
          B[i].second.first += bonus;
        }
      } else {
        EB.push_back(make_pair(bonus, name));
      }
    } else {
      if(M == sum) {
        for(int i = 0; i < C.size(); i++) if(C[i].first == home) {
          C[i].second.first += bonus;
        }
      } else {
        EC.push_back(make_pair(bonus, name));
      }
    }
  }
  if(M < sum) {
    mp.clear();
    sort(EA.begin(), EA.end());
    sort(EB.begin(), EB.end());
    sort(EC.begin(), EC.end());
    for(int i = 0; i < A.size(); i++) {
      for(int j = max(0, (int)EA.size() - A[i].second.second); j < EA.size();
          j++) {
        A[i].second.first += EA[j].first;
        mp[A[i].first].push_back(EA[j].second);
      }
    }
    for(int i = 0; i < B.size(); i++) {
      for(int j = max(0, (int)EB.size() - B[i].second.second); j < EB.size();
          j++) {
        B[i].second.first += EB[j].first;
        mp[B[i].first].push_back(EB[j].second);
      }
    }
    for(int i = 0; i < C.size(); i++) {
      for(int j = max(0, (int)EC.size() - C[i].second.second); j < EC.size();
          j++) {
        C[i].second.first += EC[j].first;
        mp[C[i].first].push_back(EC[j].second);
      }
    }
  }
  int ai = 0, bi = 0, ci = 0;
  for(int i = 1; i < A.size(); i++) {
    if(A[i].second.first > A[ai].second.first) ai = i;
  }
  for(int i = 1; i < B.size(); i++) {
    if(B[i].second.first > B[bi].second.first) bi = i;
  }
  for(int i = 1; i < C.size(); i++) {
    if(C[i].second.first > C[ci].second.first) ci = i;
  }
  if(M < sum) {
    vector<string> vv = mp[A[ai].first];
    for(int i = 0; i < vv.size(); i++) names.erase(vv[i]);
    vv = mp[B[bi].first];
    for(int i = 0; i < vv.size(); i++) names.erase(vv[i]);
    vv = mp[C[ci].first];
    for(int i = 0; i < vv.size(); i++) names.erase(vv[i]);

    while(mp[A[ai].first].size() < A[ai].second.second &&
          !names.empty()) {
      mp[A[ai].first].push_back(*names.begin());
      names.erase(names.begin());
    }
    while(mp[B[bi].first].size() < B[bi].second.second &&
          !names.empty()) {
      mp[B[bi].first].push_back(*names.begin());
      names.erase(names.begin());
    }
    while(mp[C[ci].first].size() < C[ci].second.second &&
          !names.empty()) {
      mp[C[ci].first].push_back(*names.begin());
      names.erase(names.begin());
    }
  }
  vector<string> vv = mp[A[ai].first];
  cout << A[ai].first << ' ' << vv.size();
  sort(vv.begin(), vv.end());
  for(int i = 0; i < vv.size(); i++) cout << ' ' << vv[i];
  cout << endl;

  vv = mp[B[bi].first];
  cout << B[bi].first << ' ' << vv.size();
  sort(vv.begin(), vv.end());
  for(int i = 0; i < vv.size(); i++) cout << ' ' << vv[i];
  cout << endl;

  vv = mp[C[ci].first];
  cout << C[ci].first << ' ' << vv.size();
  sort(vv.begin(), vv.end());
  for(int i = 0; i < vv.size(); i++) cout << ' ' << vv[i];
  cout << endl;
}