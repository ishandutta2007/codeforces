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

const int BASE = (1 << 18), N = 200005;

int cntTreeRed[2 * BASE + 5], cntTreeBlue[2 * BASE + 5];
long long sumTreeRed[2 * BASE + 5], sumTreeBlue[2 * BASE + 5];

int n;
int type[N], value[N];
int toValRed[N], toValBlue[N];
int totalRed, totalBlue;
int myPos[N];

void insert(long long *sumTree, int *cntTree, int pos, int c, int w) {
    pos += BASE;
    while (pos >= 1) {
        sumTree[pos] += w;
        cntTree[pos] += c;
        pos /= 2;
    }
}

void insertRed(int pos, int c, int w) {
    insert(sumTreeRed, cntTreeRed, pos, c, w);
}

void insertBlue(int pos, int c, int w) {
    insert(sumTreeBlue, cntTreeBlue, pos, c, w);
}

int getId(int *tree, int ord, int pos = 1) {
    if (pos >= BASE) {
        return pos - BASE;
    }
    if (tree[2 * pos] >= ord) {
        return getId(tree, ord, pos * 2);
    } else {
        return getId(tree, ord - tree[2 * pos], pos * 2 + 1);
    }
}

int getValRed(int ord) {
    return toValRed[getId(cntTreeRed, ord)];
}

int getValBlue(int ord) {
    return toValBlue[getId(cntTreeBlue, ord)];
}

long long querySum(long long *sumTree, int *cntTree, int total, int pos = 1) {
    if (total == 0) return 0;
    if (pos >= BASE) {
        return sumTree[pos] / cntTree[pos] * total;
    }
    if (cntTree[2 * pos] >= total) {
        return querySum(sumTree, cntTree, total, pos * 2);
    }
    return sumTree[2 * pos] + querySum(sumTree, cntTree, total - cntTree[2 * pos], pos * 2 + 1);
}

long long querySumRed(int total) {
    return querySum(sumTreeRed, cntTreeRed, total);
}

long long querySumBlue(int total) {
    return querySum(sumTreeBlue, cntTreeBlue, total);
}

long long query() {
    if (max(totalRed, totalBlue) == 0) return 0;
    if (totalRed == 0) {
        return 2 * querySumBlue(totalBlue) - querySumBlue(1);
    }
    if (totalBlue == 0) {
        return querySumRed(totalRed);
    }
    int low = 2;
    int high = min(totalBlue, totalRed);
    int res = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int valRed = getValRed(mid);
        int valBlue = getValBlue(mid);
        if (valRed >= valBlue) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return querySumRed(totalRed) + 2 * querySumBlue(totalBlue) + querySumRed(res) - querySumBlue(res);
}

int main() {
    
        scanf("%d", &n);
        vector<pair<int, int>> redValues, blueValues;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &type[i], &value[i]);
            if (type[i] == 0) {
                redValues.push_back({abs(value[i]), i});
            } else {
                blueValues.push_back({abs(value[i]), i});
            }
        }
        sort(redValues.begin(), redValues.end());
        reverse(redValues.begin(), redValues.end());
        sort(blueValues.begin(), blueValues.end());
        int id = 0;
        for (int i = 0; i < redValues.size(); i++) {
            if (i == 0 || redValues[i].first != redValues[i - 1].first) {
                id++;
            }
            myPos[redValues[i].second] = id;
            toValRed[id] = redValues[i].first;
        }
        id = 0;
        for (int i = 0; i < blueValues.size(); i++) {
            if (i == 0 || blueValues[i].first != blueValues[i - 1].first) {
                id++;
            }
            myPos[blueValues[i].second] = id;
            toValBlue[id] = blueValues[i].first;
        }
        
        totalRed = 0;
        totalBlue = 0;
        for (int i = 1; i <= n; i++) {
            if (type[i] == 0) {
                if (value[i] > 0) {
                    insertRed(myPos[i], 1, value[i]);
                    totalRed++;
                } else {
                    insertRed(myPos[i], -1, value[i]);
                    totalRed--;
                }
            } else {
                if (value[i] > 0) {
                    insertBlue(myPos[i], 1, value[i]);
                    totalBlue++;
                } else {
                    insertBlue(myPos[i], -1, value[i]);
                    totalBlue--;
                }
            }
            printf("%lld\n", query());
        }
    
    
    return 0;
}