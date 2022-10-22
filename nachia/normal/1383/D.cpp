#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int H,W;
int Y[251];
int X[251];
int ans[250][250]={};
int wit[250][250]={};
bool used[70000]={};
struct P{
 int x,y;
 bool operator<(const P& r) const{
  return wit[x][y] < wit[r.x][r.y];
 }
};
vector<P> V;

int main() {
 scanf("%d%d",&H,&W);
 rep(y,H) Y[y]=0;
 rep(x,W) X[x]=0;
 rep(y,H) rep(x,W){
  int a; scanf("%d",&a);
  Y[y]=max(Y[y],a);
  X[x]=max(X[x],a);
 }
 sort(X,X+W,greater<int>()); X[W]=0;
 sort(Y,Y+H,greater<int>()); Y[H]=0;

 {
  int x,y; x=y=0;
  int pp=0;
  while(x+y<W+H){
   if(X[x]==Y[y]){
    ans[x][y]=X[x];
    for(int xx=x-1; xx>=0; xx--){ wit[xx][y]=pp++; } y++;
    for(int yy=y-1; yy>=0; yy--){ wit[x][yy]=pp++; } x++;
   }
   else if(X[x]<Y[y]){
    ans[x-1][y]=Y[y];
    for(int xx=x-1; xx>=0; xx--){ wit[xx][y]=pp++; } y++;
   }
   else {
    ans[x][y-1]=X[x];
    for(int yy=y-1; yy>=0; yy--){ wit[x][yy]=pp++; } x++;
   }
  }
 }

 rep(x,W)rep(y,H){
  if(ans[x][y]!=0) continue;
  V.push_back({x,y});
 }
 sort(V.begin(),V.end());

 rep(x,W) used[X[x]]=true;
 rep(y,H) used[Y[y]]=true;

 int p=W*H;
 rep(i,V.size()){
  while(used[p]) p--;
  ans[V[i].x][V[i].y]=p;
  used[p]=true;
 }


 rep(y,H){
  rep(x,W){ if(x) printf(" "); printf("%u",ans[x][y]); }
  printf("\n");
 }

 return 0;
}