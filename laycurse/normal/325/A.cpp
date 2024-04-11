#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int x1[10], x2[10], y1[10], y2[10];
  set<int> setX, setY;
  set<int>::iterator it;
  map<int,int> mapX, mapY;
  int mp[50][50], X, Y;
  int mn_x, mx_x, mn_y, mx_y;

  scanf("%d",&n);
  rep(i,n) scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);

  mn_x = mx_x = x1[0];
  rep(i,n) mn_x = min(mn_x, min(x1[i],x2[i]));
  rep(i,n) mx_x = max(mx_x, max(x1[i],x2[i]));
  mn_y = mx_y = y1[0];
  rep(i,n) mn_y = min(mn_y, min(y1[i],y2[i]));
  rep(i,n) mx_y = max(mx_y, max(y1[i],y2[i]));

  if(mx_y-mn_y != mx_x-mn_x){
    puts("NO");
    return 0;
  }

  rep(i,n) setX.insert(x1[i]), setX.insert(x2[i]);
  rep(i,n) setY.insert(y1[i]), setY.insert(y2[i]);

  k = 0;
  for(it=setX.begin();it!=setX.end();it++) mapX[*it] = k++;
  X = k-1;
  k = 0;
  for(it=setY.begin();it!=setY.end();it++) mapY[*it] = k++;
  Y = k-1;

  rep(i,n) x1[i] = mapX[x1[i]], x2[i] = mapX[x2[i]];
  rep(i,n) y1[i] = mapY[y1[i]], y2[i] = mapY[y2[i]];

  rep(i,X) rep(j,Y) mp[i][j] = 0;
  rep(k,n) REP(i,x1[k],x2[k]) REP(j,y1[k],y2[k]) mp[i][j]++;

  k = 0;
  rep(i,X) rep(j,Y) if(mp[i][j]!=1) k++;

/*  rep(i,X){ rep(j,Y) printf("%d",mp[i][j]); puts(""); }*/

  if(k==0) puts("YES");
  else puts("NO");

  return 0;
}