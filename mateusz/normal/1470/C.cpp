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

int n, k;
int per[100005];

int query(int pos) {
    cout << "? " << pos << endl;
    int ret;
    cin >> ret;
    return ret;
}


int main() {
    srand(time(0));
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        per[i] = i;
    }
    random_shuffle(per + 1, per + 1 + n);
    int lower = -1;
    int greater = -1;
    
    int steps = 0;
    while (lower == -1 || greater == -1) {
        int id = per[++steps];
        if (steps == n) steps = 0;
        int val = query(id);
        if (lower == -1 && val < k) {
            lower = id;
        }
        if (greater == -1 && val > k) {
            greater = id;
        }
    }
    
    int dist = greater - lower;
    if (dist < 0) dist += n;
    int low = 1;
    int high = dist - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int pos = lower + mid;
        if (pos > n) pos -= n;
        int val = query(pos);
        if (val == k) {
            cout << "! " << pos << endl;
            return 0;
        }
        if (val > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    

    
    assert(false);
    return 0;
}