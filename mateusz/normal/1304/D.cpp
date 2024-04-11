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

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005;

int n;
char tab[N];

void test() {
    scanf(" %d", &n);
    scanf(" %s", &tab[1]);
    
    int cntUp = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] == '<') cntUp++;
    }
    
    int initVal = n - cntUp;
    int ptr1 = initVal;
    int ptr2 = initVal - 1;
    vector<int> seq;
//     if (tab[1] == '<') {
        seq.push_back(ptr1++);
//     }
    for (int i = 1; i < n; i++) {
        if (tab[i] == '<') {
            seq.push_back(ptr1++);
        } else {
            seq.push_back(ptr2--);
        }
    }
    
    
    int ptr = 0;
    vector<int> seq2;
    for (int i = n - 1; i >= 1; i--) {
        int cnt = 0;
        while (i >= 1 && tab[i] == '<') {
            cnt++;
            i--;
        }
        for (int j = ptr + cnt + 1; j > ptr; j--) {
            seq2.push_back(j);
        } 
        ptr = ptr + cnt + 1;
    } 
    if (tab[1] == '>') {
        seq2.push_back(ptr + 1);
    }
    reverse(seq2.begin(), seq2.end());
    debug(seq.size(), seq2.size());
    for (int x : seq2) {
        printf("%d ", x);
    }
    printf("\n");
    for (int x : seq) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    
    return 0;
}