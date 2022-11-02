#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct node{
       int x, position;
       node(int A, int B):x(A), position(B){}
       bool operator < (const node &A) const{
            if (x != A.x) return x < A.x;
            return position < A.position;
       }
};
const int M = 137, P = 999971;
int first[P], l, next[100001], where[100001][2];
int n, Q[100001][2], a[100001][2], v[100001][2];
vector<node> row[100001], line[100001];
set<node> events;

inline void insert(int x, int y, int z){
    where[++l][0] = y;
    where[l][1] = z;
    next[l] = first[x];
    first[x] = l;
}

bool find(int y, int z){
     int will = (y * M + z) % P;
     for (int x = first[will]; x; x = next[x])
         if (where[x][0] == y && where[x][1] == z) return true;
     return false;
}

int main(){
    //freopen("d.in", "r", stdin);
   // freopen("d.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i <= 100000; i++) row[i].clear(), line[i].clear();
    //events.clear();
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Q[i][0] = x; Q[i][1] = y;
        node A = node(x, y);
        insert((x * M + y) % P, x, y);
        row[x].push_back(node(y, i));
        line[y].push_back(node(x, i));
    }
    for (int i = 0; i <= 100000; i++)
    {
        sort(row[i].begin(), row[i].end());
        for (int j = 0; j < row[i].size(); j++)
            a[row[i][j].position][0] = i,
            a[row[i][j].position][1] = j;
        sort(line[i].begin(), line[i].end());
        for (int j = 0; j < line[i].size(); j++)
            v[line[i][j].position][0] = i,
            v[line[i][j].position][1] = j;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (row[a[i][0]].size() - a[i][1] < line[v[i][0]].size() - v[i][1])
           for (int j = a[i][1] + 1; j < row[a[i][0]].size(); j++)
           {
               int delta = row[a[i][0]][j].x - row[a[i][0]][a[i][1]].x;
               if (!find(Q[i][0] + delta, Q[i][1])) continue;
               if (!find(Q[i][0], Q[i][1] + delta)) continue;
               if (!find(Q[i][0] + delta, Q[i][1] + delta)) continue;
             //  if (events.find(node()) == events.end()) continue;
             //  if (events.find(node(Q[i][0], Q[i][1] + delta)) == events.end()) continue;
             //  if (events.find(node(Q[i][0] + delta, Q[i][1] + delta)) == events.end()) continue;
               ++ans;
           }
        else
           for (int j = v[i][1] + 1; j < line[v[i][0]].size(); j++)
           {
               int delta = line[v[i][0]][j].x - line[v[i][0]][v[i][1]].x;
               if (!find(Q[i][0] + delta, Q[i][1])) continue;
               if (!find(Q[i][0], Q[i][1] + delta)) continue;
               if (!find(Q[i][0] + delta, Q[i][1] + delta)) continue;
             //  if (events.find(node(Q[i][0] + delta, Q[i][1])) == events.end()) continue;
             //  if (events.find(node(Q[i][0], Q[i][1] + delta)) == events.end()) continue;
              // printf("%d %d %d\n", Q[i][0] + delta, Q[i][1] + delta, delta);
             //  if (events.find(node(Q[i][0] + delta, Q[i][1] + delta)) == events.end()) continue;
               ++ans;
           }
    }
    cout << ans << endl;
}