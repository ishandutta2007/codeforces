#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 205;
const int Maxm = 531445;
const int Maxk = Maxn + Maxm + 5;

int n;
vector <int> neigh[Maxk];
map <int, int> canflow[Maxk];
int flow[Maxk], p[Maxk];
int res;

void Add(int v, int u)
{
     if (canflow[v].find(n + u) == canflow[v].end()) {
                            neigh[v].push_back(n + u);
                            neigh[n + u].push_back(v);
                            canflow[v][n + u] = 1;
     }
}

int getVal(const string &s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
       res = 27 * res + s[i] - 'a' + 1;
    return res;
}

string getString(int val)
{
    string res;
    while (val) {
          char c = char(val % 27 - 1 + 'a');
          string toadd(1, c);
          res = toadd + res;
          val /= 27;
    }
    return res;
}

int getFlow()
{
    fill(flow, flow + Maxk, 0); flow[0] = 1000000000;
    priority_queue <int> Q; Q.push(0);
    int v;
    while (!Q.empty()) {
          v = Q.top(); Q.pop();
          if (v == n + Maxm) break;
          for (int i = 0; i < neigh[v].size(); i++) {
              int u = neigh[v][i];
              int candflow = min(flow[v], canflow[v][u]);
              if (candflow > flow[u]) {
                           flow[u] = candflow;
                           p[u] = v;
                           Q.push(u);
              }
          }
    }
    if (v != n + Maxm) return 0;
    int ret = flow[n + Maxm];
    while (v) {
          int u = p[v];
          canflow[u][v] -= ret;
          canflow[v][u] += ret;
          v = u;
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        neigh[0].push_back(i);
        neigh[i].push_back(0);
        canflow[0][i] = 1;
    }
    for (int i = n + 1; i < n + Maxm; i++) {
        neigh[i].push_back(n + Maxm);
        neigh[n + Maxm].push_back(i);
        canflow[i][n + Maxm] = 1;
    }
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int i1 = 0; i1 < s.length(); i1++) {
            string tmp(1, s[i1]);
            Add(i, getVal(tmp));
            for (int i2 = i1 + 1; i2 < s.length(); i2++) {
                tmp += s[i2];
                Add(i, getVal(tmp));
                for (int i3 = i2 + 1; i3 < s.length(); i3++) {
                    tmp += s[i3];
                    Add(i, getVal(tmp));
                    for (int i4 = i3 + 1; i4 < s.length(); i4++) {
                        tmp += s[i4];
                        Add(i, getVal(tmp));
                        tmp.erase(tmp.length() - 1, 1);
                    }
                    tmp.erase(tmp.length() - 1, 1);
                }
                tmp.erase(tmp.length() - 1, 1);
            }
        }
    }
    int flow;
    while ((flow = getFlow()) != 0) res += flow;
    if (res == n) {
       for (int i = 1; i <= n; i++)
          for (map <int, int>::iterator it = canflow[i].begin(); it != canflow[i].end(); it++)
             if (it->second == 0) {
                            cout << getString(it->first - n) << endl;
                            break;
             }
    } else cout << "-1\n";
    return 0;
}