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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005, BASE = (1 << 18);

int n, m;
char play[N];
int rocksTree[2 * BASE + 5], scissorsTree[2 * BASE + 5], papersTree[2 * BASE + 5];
set<int> scissors, papers, rocks;

void insert(int *tree, int pos, int val) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] += val;
        pos /= 2;
    }
}

int queryTree(int *tree, int posa, int posb) {
    if (posa > posb) return 0;
    posa += BASE;
    posb += BASE;
    int ret = tree[posa];
    if (posa != posb) {
        ret += tree[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret += tree[posa + 1];
        }
        if (posb % 2 == 1) {
            ret += tree[posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int query() {
    int all = n;
    
    // remove bad rocks
    if (papers.size() > 0) {
        if (scissors.size() == 0) {
            all -= rocks.size();
        } else {
            int to = *scissors.begin() - 1;
            int from = *papers.begin() + 1;
            all -= queryTree(rocksTree, from, to);
            
            from = *scissors.rbegin() + 1;
            to = *papers.rbegin() - 1;
            all -= queryTree(rocksTree, from, to);
        }
    }
    
    // remove bad scissors;
    if (rocks.size() > 0) {
        if (papers.size() == 0) {
            all -= scissors.size();
        } else {
            int to = *papers.begin() - 1;
            int from = *rocks.begin() + 1;
            all -= queryTree(scissorsTree, from, to);
            from = *papers.rbegin() + 1;
            to = *rocks.rbegin() - 1;
            all -= queryTree(scissorsTree, from, to);
        }
    }
    
    // remove bad papers;
    if (scissors.size() > 0) {
        if (rocks.size() == 0) {
            all -= papers.size();
        } else {
            int to = *rocks.begin() - 1;
            int from = *scissors.begin() + 1;
            all -= queryTree(papersTree, from, to);
            from = *rocks.rbegin() + 1;
            to = *scissors.rbegin() - 1;
            all -= queryTree(papersTree, from, to);
        }
    }
    
    return all;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    scanf("%s", &play[1]);
    
    for (int i = 1; i <= n; i++) {
        if (play[i] == 'R') {
            rocks.insert(i);
            insert(rocksTree, i, 1);
        } else if (play[i] == 'S') {
            scissors.insert(i);
            insert(scissorsTree, i, 1);
        } else {
            papers.insert(i);
            insert(papersTree, i, 1);
        }
    }
    
    printf("%d\n", query());
    
    while (m--) {
        int i;
        char type;
        scanf("%d %c", &i, &type);
        if (play[i] == 'R') {
            rocks.erase(i);
            insert(rocksTree, i, -1);
        } else if (play[i] == 'S') {
            scissors.erase(i);
            insert(scissorsTree, i, -1);
        } else {
            papers.erase(i);
            insert(papersTree, i, -1);
        }
        
        play[i] = type;
        
        if (play[i] == 'R') {
            rocks.insert(i);
            insert(rocksTree, i, 1);
        } else if (play[i] == 'S') {
            scissors.insert(i);
            insert(scissorsTree, i, 1);
        } else {
            papers.insert(i);
            insert(papersTree, i, 1);
        }
        
        printf("%d\n", query());
    }
    
    return 0;
}