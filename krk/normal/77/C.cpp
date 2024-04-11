#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100001;

ll n, s, best[Maxn], canget[Maxn], beav[Maxn];
vector <int> neigh[Maxn];
vector <ll> greed;
stack <int> S, P, From;

int main()
{
    ll sum;
    int a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> beav[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    cin >> s; S.push(s); P.push(-1); From.push(0);
    while (!S.empty()) {
          if (From.top() == neigh[S.top()].size()) {
                         int v = S.top(), p = P.top();
                         S.pop(); P.pop(); From.pop();
                         greed.clear(); sum = 0;
                         for (int i = 0; i < neigh[v].size(); i++) 
                            if (neigh[v][i] != p && beav[neigh[v][i]]) {
                                 greed.push_back(best[neigh[v][i]]); 
                                 sum += canget[neigh[v][i]];
                            }
                         sort(greed.begin(), greed.end());
                         ll lft = beav[v];
                         if (v != s) { lft--; best[v] = 1; }
                         for (int i = greed.size()-1; i >= 0 && lft; i--) {
                             best[v] += greed[i] + 1;
                             lft--;
                         }
                         best[v] += 2 * min(lft, sum); lft -= min(lft, sum);
                         canget[v] = lft;
          } else {
                 int fr = From.top(); From.pop(); From.push(fr+1);
                 if (neigh[S.top()][fr] != P.top() && beav[neigh[S.top()][fr]]) {
                                        int v = S.top();
                                        S.push(neigh[v][fr]); P.push(v); From.push(0);
                 }
          }
    }
    cout << best[s] << endl;
    return 0;
}