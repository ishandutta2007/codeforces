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

const int N = 1000005;

int n;
int pos;
int totalOpen, totalClose;
int maxRight[N], minRight[N], maxLeft[N], minLeft[N];
int curState;
char curWord[N];

char word[N];

void removeOpen() {
    maxRight[pos]--;
    minRight[pos]--;
    curState--;
    maxLeft[pos] = max(maxLeft[pos - 1], curState);
    minLeft[pos] = min(minLeft[pos - 1], curState);
}

void addOpen() {
    maxRight[pos]++;
    minRight[pos]++;
    curState++;
    maxLeft[pos] = max(maxLeft[pos - 1], curState);
    minLeft[pos] = min(minLeft[pos - 1], curState);
}

void addClose() {
    removeOpen();
}

void removeClose() {
    addOpen();
}

void setLetter(char c) {
    if (curWord[pos] == '(') {
        removeOpen();
        totalOpen--;
    }
    if (curWord[pos] == ')') {
        removeClose();
        totalClose--;
    }
    curWord[pos] = c;
    if (curWord[pos] == '(') {
        addOpen();
        totalOpen++;
    }
    if (curWord[pos] == ')') {
        addClose();
        totalClose++;
    }
}

int chrToVal(char c) {
    if (c == '(') return 1;
    if (c == ')') return -1;
    return 0;
}

void moveLeft() {
    if (pos == 1) return;
    if (curWord[pos] == '(') curState--;
    else if (curWord[pos] == ')') curState++;
    pos--;
    maxRight[pos] = max(maxRight[pos + 1], 0) + chrToVal(curWord[pos]);
    minRight[pos] = min(minRight[pos + 1], 0) + chrToVal(curWord[pos]);
}

void moveRight() {
    pos++;
    if (curWord[pos] == '(') curState++;
    else if (curWord[pos] == ')') curState--;
    maxLeft[pos] = max(maxLeft[pos - 1], curState);
    minLeft[pos] = min(minLeft[pos - 1], curState);
}

int getMin() {
    return min(minLeft[pos], curState + minRight[pos] - chrToVal(curWord[pos]));
}

int getMax() {
    return max(maxLeft[pos], curState + maxRight[pos] - chrToVal(curWord[pos]));
}

int main() {
    
    scanf("%d", &n);
    scanf("%s", &word[1]);
    pos = 1;
    
    for (int i = 1; i <= n; i++) {
        if (word[i] == 'L') moveLeft();
        else if (word[i] == 'R') moveRight();
        else setLetter(word[i]);
        
        if (getMin() == 0 && totalOpen == totalClose) {
            printf("%d ", getMax());
        } else {
            printf("-1 ");
        }
    }
    
    return 0;
}