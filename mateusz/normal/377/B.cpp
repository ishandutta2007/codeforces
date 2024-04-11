#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(0);

using namespace std;

const int N = 100005;
int n, m, s;
pair<int, int>bug[N];
int skill[N], cost[N], tab[N], kto[N], kto2[N];
priority_queue<pair<int, int> >Q, Q2;

bool cmp(int a, int b) {
  return skill[a] < skill[b];
}



bool git(int days) {
  while(!Q.empty()) Q.pop();
  int wsk = m;
  int curcost = 0;
  for(int i = n; i >= 1; i--) {
    int B = bug[i].ff;
    while(wsk >= 1 && skill[tab[wsk]] >= B) {
      Q.push(MP(-cost[tab[wsk]], tab[wsk]));
      wsk--;
    }
    if(Q.empty()) {
      return 0;
    } else {
      int w = -Q.top().ff;
      if(curcost + w <= s) {
    curcost += w;
    int in = Q.top().ss;
    Q.pop();
    int nxt = i - days;
    while(i > 0 && i > nxt) {
      kto2[bug[i].ss] = in;
      i--;
    }
    i++;
      } 
      else return 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    kto[i] = kto2[i];
    kto2[i] = 0;
  }
  return 1;
}



int main() {
  
  scanf("%d%d%d", &n, &m, &s);
  swap(n, m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &bug[i].ff);
    bug[i].ss = i;
  }
  sort(bug + 1, bug + 1 + n);
  
  for(int i = 1; i <= m; i++) {
    scanf("%d", &skill[i]);
  }
  for(int i = 1; i <= m; i++) {
    scanf("%d", &cost[i]);
  }
  for(int i = 1; i <= m; i++) {
    tab[i] = i;
  }
  sort(tab + 1, tab + 1 + m, cmp);
  
  int low = 1;
  int high = n;
  int res = n + 1;
  while(low <= high) {
    int mid = (low + high) / 2;
    if(git(mid)) {
      res = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  
  if(res == n + 1) {
    printf("NO");
    return 0;
  }
  
  printf("YES\n");
  for(int i = 1; i <= n; i++) {
    printf("%d ", kto[i]);
  }
  
  
  return 0;
}