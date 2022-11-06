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

#ifdef LOCAL
#define  debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define  debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

int n;
long long S;
int a, b, val[N], cost[N];
vector<pair<int, int> > V[N];
long long sumLeafs[N], leafSum[N];

void DFS(int w, int par = -1) {
    bool isLeaf = (w == 1 && V[w].empty()) || (w != 1 && V[w].size() == 1);
    leafSum[w] = isLeaf;
    for (auto e : V[w]) {
        int u = e.first;
        int id = e.second;
        if (par == u) continue;
        DFS(u, w);
        leafSum[w] += leafSum[u];
        sumLeafs[id] = leafSum[u];
    }
}

long long oneTime(long long v, long long l) {
    return (v + 1) / 2 * l;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &n, &S);
        for (int i = 1; i <= n; i++) {
            V[i].clear();
            sumLeafs[i] = leafSum[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d %d %d %d", &a, &b, &val[i], &cost[i]);
            V[a].push_back({b, i});
            V[b].push_back({a, i});
        }
        
        DFS(1);
        priority_queue<pair<long long, pair<long long, long long>>> Q1, Q2;
        long long currentSum = 0;
        for (int i = 2; i <= n; i++) {
            if (cost[i] == 1) {
                Q1.push({oneTime(val[i], sumLeafs[i]), {val[i], sumLeafs[i]}});
            } else {
                Q2.push({oneTime(val[i], sumLeafs[i]), {val[i], sumLeafs[i]}});
            }
            currentSum += sumLeafs[i] * val[i];
        }
        
        long long ans = 0;
        while (currentSum > S) {
            // debug(currentSum, S, ans);
            if (Q2.empty()) {
                auto p = Q1.top();
                Q1.pop();
                auto v = p.second.first;
                auto l = p.second.second;
                currentSum -= p.first;
                // debug(v, l);
                Q1.push({oneTime(v / 2, l), {v / 2, l}});
                ans++;
                continue;
            }
            if (Q1.empty()) {
                auto p = Q2.top();
                Q2.pop();
                auto v = p.second.first;
                auto l = p.second.second;
                currentSum -= p.first;
                // debug(v, l);
                Q2.push({oneTime(v / 2, l), {v / 2, l}});
                ans += 2;
                continue;
            }
            
            auto p2 = Q2.top();
            long long gain2 = p2.first;
            
            auto p1 = Q1.top();
            Q1.pop();
            long long gain1 = p1.first;
            auto v = p1.second.first;
            auto l = p1.second.second;
            auto pp1 = make_pair(oneTime(v / 2, l), make_pair(v / 2, l));
            if (!Q1.empty()) {
                auto tmp = Q1.top();
                if (tmp.first > pp1.first) {
                    pp1 = tmp;
                }
            }
            gain1 += pp1.first;
            Q1.push(p1);
            if (gain2 >= gain1 && currentSum - p1.first > S) {
                auto p = Q2.top();
                Q2.pop();
                auto v = p.second.first;
                auto l = p.second.second;
                currentSum -= p.first;
                // debug(v, l);
                Q2.push({oneTime(v / 2, l), {v / 2, l}});
                ans += 2;
                continue;
            } else {
                auto p = Q1.top();
                Q1.pop();
                auto v = p.second.first;
                auto l = p.second.second;
                currentSum -= p.first;
                // debug(v, l);
                Q1.push({oneTime(v / 2, l), {v / 2, l}});
                ans++;
                continue;
            }
        }
        
        printf("%lld\n", ans);
    }
    
    
    
    return 0;
}