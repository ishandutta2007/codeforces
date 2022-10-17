#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 310000, B=1<<19;
int n,p[N],q[N];
int base,tp[2*B],tqsum[2*B],tqmin[2*B];
int posi[N];

void update_max(int x, int val) {
  tp[x+=base] = val;
  while (x > 1) { x /= 2; tp[x] = max(tp[2*x], tp[2*x+1]); }
}
int query_max(int x) {
  int ans = tp[x+=base];
  while (x > 1) {
    if (x&1) { ans = max(ans, tp[x-1]); }
    x /= 2;
  }
  return ans;
}

void update_q(int x, int val) {
  tqsum[x+=base] += val;
  tqmin[x] = tqsum[x];
  while (x > 1) { x /= 2;
    tqsum[x] = tqsum[2*x] + tqsum[2*x+1];
    tqmin[x] = min(tqmin[2*x], tqsum[2*x] + tqmin[2*x+1]);
  }
}
int query_sum(int x) {
  int ans = tqsum[x+=base];
  while (x > 1) {
    if (x&1) { ans += tqsum[x-1]; }
    x /= 2;
  }
  return ans;
}

int next_zero(int x) {
  int sum = query_sum(x);
//  printf("sum=%d\n",sum);
  if (sum == 0) return x;
  x+=base;
  while (x > 1) {
    if (~x&1) if (sum + tqmin[x+1] == 0) {
      x++;
      while (x < base) {
        if (sum + tqmin[2*x] == 0) { x *= 2; }
        else { sum += tqsum[2*x]; x = 2*x+1; }
      }
      return x-base;
    }
    if (~x&1) sum += tqsum[x+1];
    x /= 2;
  }
  return -100;
}


int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&p[i]); --p[i]; }
  REP(i,n) { scanf("%d",&q[i]); --q[i]; }
  REP(i,n) posi[p[i]] = i;

  base=1;
  while (base < n) { base *= 2; }

  REP(i,n) tp[base + i] = p[i];
  for(int i=base-1; i>0; --i) tp[i] = max(tp[2*i], tp[2*i+1]);

  REP(i,n) {
    printf("%d ", tp[1]+1);
    int pos = q[i];
    int pos2 = next_zero(pos);
    int val = query_max(pos2);
    update_max(posi[val], -1);

//    int uu=0;
//    REP(j,n) { uu += tqsum[base+j]; printf("%d ",uu); } printf("\n");
//    printf("pos=%d  pos2=%d  val=%d  posi=%d\n",pos,pos2,val,posi[val]);

    update_q(posi[val], 1);
    update_q(pos, -1);
  }
  printf("\n");
}