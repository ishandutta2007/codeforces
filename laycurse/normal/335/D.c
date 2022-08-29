#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int mp[3100][3100];
int dp[3100][3100];
int up[3100][3100], right[3100][3100];
int up2[3100][3100], right2[3100][3100];

int xst[110000], xed[110000], yst[110000], yed[110000];
int res[110000], res_size;

int is_fill(int x1, int y1, int x2, int y2){
  int area = dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1];
  if(area == (x2-x1)*(y2-y1)) return 1;
  return 0;
}

int main(){
  int i,j,k,l,m,n;
  int a, b, c;
  int fg;

  scanf("%d",&n);
  rep(i,n) scanf("%d%d%d%d",xst+i,yst+i,xed+i,yed+i);

  rep(i,3020) rep(j,3020) mp[i][j] = -1;
  rep(k,n) REP(i,xst[k],xed[k]) REP(j,yst[k],yed[k]) mp[i][j] = k+1;

  rep(i,3020) dp[i][0] = dp[0][i] = 0;
  REP(i,1,3020) REP(j,1,3020){
    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    if(mp[i-1][j-1] != -1) dp[i][j]++;
  }

  for(i=3010;i>=0;i--) for(j=3010;j>=0;j--){
    up[i][j] = right[i][j] = 0;
    up2[i][j] = right2[i][j] = 0;
    if(mp[i][j]==-1) continue;
    if(i==0 || mp[i-1][j]!=mp[i][j]) up[i][j] = up[i][j+1] + 1;
    if(j==0 || mp[i][j-1]!=mp[i][j]) right[i][j] = right[i+1][j] + 1;
    if(mp[i+1][j]!=mp[i][j]) up2[i][j] = up2[i][j+1] + 1;
    if(mp[i][j+1]!=mp[i][j]) right2[i][j] = right2[i+1][j] + 1;
  }

  fg = 0;
  rep(i,3010) rep(j,3010) if(!fg){
    m = up[i][j];
    if(m > right[i][j]) m = right[i][j];
    REP(k,1,m+1){
      if(is_fill(i,j,i+k,j+k)==0) break;
      if(up2[i+k-1][j] >= k && right2[i][j+k-1] >= k){
        rep(a,n+1) res[a] = 0;
        REP(a,i,i+k) REP(b,j,j+k) if(mp[a][b]>=0) res[mp[a][b]] = 1;
        c = 0;
        rep(a,n+1) c += res[a];
        printf("YES %d\n",c);
        rep(a,n+1) if(res[a]) printf("%d ",a); puts("");
        fg = 1; break;
      }
    }
  }
  if(!fg) puts("NO");

  return 0;
}