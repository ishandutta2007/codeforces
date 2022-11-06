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

const int B = (1 << 18), N = 20;

int BASE;
long long tree[2 * B + 5];
int n, q, x, y, type;
bool reversed[N], swapped[N];

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        pos /= 2;
    }
} 

int findRealPos(int pos, int w, int level) {
    if (w >= BASE) {
        assert(level == 0);
        return w - BASE;
    }
    if (reversed[level]) {
        pos = (1 << level) - 1 - pos;
    }
    int left = 2 * w;
    int right = 2 * w + 1;
    if (swapped[level]) {
        swap(left, right);
    }
    if (pos < (1 << (level - 1))) {
            return findRealPos(pos, left, level - 1);
        } else {
            return findRealPos(pos - (1 << (level - 1)), right, level - 1);
        }
}

void change(int pos, int w) {
    int realPos = findRealPos(pos, 1, n);
    insert(realPos, w);
}

long long query(int ile, int level, int w = 1, bool rev = false) {
    if (ile <= 0) {
        return 0;
    }
    if (w >= BASE) {
        return tree[w];
    }
    rev ^= reversed[level];
    int left = 2 * w;
    int right = 2 * w + 1;
    if (swapped[level]) {
        swap(left, right);
    }
    if (!rev) {
        if ((1 << (level - 1)) >= ile) {
            return query(ile, level - 1, left, rev);
        } else {
            return tree[left] + query(ile - (1 << (level - 1)), level - 1, right, rev);
        }
    } else {
        if ((1 << (level - 1)) >= ile ) {
            return query(ile, level - 1, right, rev);
        } else {
            return tree[right] + query(ile - (1 << (level - 1)), level - 1, left, rev);
        }
    }
}

int main() {
    
    scanf("%d %d", &n, &q);
    BASE = (1 << n);
    
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", &x);
        insert(i, x);
    }
    
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &x, &y);
            change(x - 1, y);
        } else if (type == 2) {
            scanf("%d", &x);
            reversed[x] ^= 1;
        } else if (type == 3) {
            scanf("%d", &x);
            swapped[x + 1] ^= 1;
        } else {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(y, n) - query(x - 1, n));
        }
    }
    
    return 0;
}