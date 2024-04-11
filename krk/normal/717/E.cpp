#include <bits/stdc++.h>
using namespace std;

int n,root,resbr,num[333555],res[5333555],cale[333555];
bool b[333555],sb[333555],mark[333555];

vector<int> adj[333555];

void idar(int x) {
  
    int i,y,sz;
  
    res[resbr++] = x;
    if (resbr > 1) b[x] = !b[x];
  
    mark[x] = true;
  
    sz = adj[x].size();
    for(i=0; i<sz; i++) {
       y = adj[x][i];
      
       if (!mark[y]) {
          cale[y] = x;
          idar(y);
          
          res[resbr++] = x;
          b[x] = !b[x];
       }
    }
      
    if (!b[x]) {
      if (x == root) {
        res[resbr++] = adj[x][0];
        res[resbr++] = root;
        res[resbr++] = adj[x][0];
      } else {
        res[resbr++] = cale[x];
        b[cale[x]] = !b[cale[x]];
        res[resbr++] = x;
        b[x] = !b[x];
      }
    }
  
}

int main() {
  
  int x,i,y;
  
  root = 0;
  bool ok = false;
  
  scanf("%d", &n);

  for(i=0; i<n; i++) {
    scanf("%d", &x);
    if (x>0) b[i] = true; else b[i] = false;
    
    if (!b[i]) ok = true;
    sb[i] = b[i];
    
  }
  
  for(i=0; i<n-1; i++) {
    scanf("%d%d", &x, &y);
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
      
  if (!ok) {
    printf("1\n");
    return 0;
  }
  
  resbr = 0;
  idar(root);
      
  for(i=0; i<resbr; i++) printf("%d ", res[i]+1);
  printf("\n");
  
  // check
  /*
  for(i=1; i<resbr; i++) {
    num[res[i]]++;
  }
  for(i=0; i<n; i++) {
    //printf("%d %d\n", num[i], sb[i]);
    if ((num[i]%2 == 0) && !sb[i]) printf("LOS %d\n", i+1);
    if ((num[i]%2 == 1) && sb[i]) printf("LOS %d\n", i+1);
  }
  */
  
  
  return 0;
}