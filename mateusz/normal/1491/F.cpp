#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int n, s;

int query(vector<int> left, vector<int> right) {
    cout << "? " << left.size() << " " << right.size() << endl;
    for (int x : left) {
        cout << x << " ";
    }
    cout << endl;
    for (int x : right) {
        cout << x << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    if (res > n) exit(0);
    return res;
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        
        int res = -1;
        int k = -1;
        for (int i = 1; i + 1 <= n; i++) {
            vector<int> left, right;
            right.push_back(i);
            for (int j = i + 1; j <= n; j++) {
                left.push_back(j);
            }
            res = query(left, right);
            if (res != 0) {
                k = i;
                break;
            }
        }
        
        set<int> ans;
        int delta = 0;
        for (int i = k + 1; i < n; i++) {
            vector<int> left = {i}, right = {k};
            int r = query(left, right);
            if (r == 0) {
                ans.insert(i);
            }
            delta += r;
        }
        
        res -= delta;
        if (res == 0) ans.insert(n);
        
        int id = k;
        int low = 1;
        int high = k - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> left = {k};
            vector<int> right;
            for (int j = 1; j <= mid; j++) {
                right.push_back(j);
            }
            res = query(left, right);
            if (res != 0) {
                id = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (int i = 1; i < k; i++) {
            if (id != i) {
                ans.insert(i);
            }
        }
        
        cout << "! " << ans.size() << " ";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}