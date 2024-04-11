#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int a[52000], b[52000];
int imp1[12000], imp2[12000];
int mn[12000], mx[12000];
int res[12000];

int main(){
  int i,j,k,l,m,n;
  int up, down, dame;

  scanf("%d%d",&n,&m);
  rep(i,m) scanf("%d%d",a+i,b+i), a[i]--, b[i]--;

  rep(i,n) mn[i] = 0, mx[i] = 2*n;
  mx[0] = 0;

  rep(i,n) imp1[i] = imp2[i] = 0;
  imp1[0] = 1;
  for(;;){
    int fg = 0;
    rep(i,m) if(imp1[a[i]] && !imp1[b[i]]) imp1[b[i]]=1, fg = 1;
    if(!fg) break;
  }
  
  imp2[n-1] = 1;
  for(;;){
    int fg = 0;
    rep(i,m) if(imp2[b[i]] && !imp2[a[i]]) imp2[a[i]]=1, fg = 1;
    if(!fg) break;
  }
  

  dame = 0;

  for(;;){
    int fg = 0;
    rep(i,m){
      j = a[i]; k = b[i];
      if(!imp1[j] || !imp1[k]) continue;
      if(!imp2[j] || !imp2[k]) continue;

      up = mx[j] + 2;
      down = mn[j] + 1;
      if(mx[k] > up) mx[k] = up, fg++;
      if(mn[k] < down) mn[k] = down, fg++;

      up = mx[k] - 1;
      down = mn[k] - 2;
      if(mx[j] > up) mx[j] = up, fg++;
      if(mn[j] < down) mn[j] = down, fg++;

    }
    rep(i,n) if(mx[i] < mn[i]) dame = 1;
    if(dame || !fg) break;
  }

  if(dame){
    puts("No");
    return 0;
  }

  rep(i,m){
    if(!imp1[b[i]] || !imp1[a[i]]){ res[i] = 1; continue; }
    if(!imp2[b[i]] || !imp2[a[i]]){ res[i] = 1; continue; }
    j = mn[b[i]] - mn[a[i]];
    assert( j >= 0 );
    if(!(j==1 || j==2)){ k = 1; break; }
    res[i] = j;
  }

  puts("Yes");
  rep(i,m) printf("%d\n",res[i]);

  return 0;
}