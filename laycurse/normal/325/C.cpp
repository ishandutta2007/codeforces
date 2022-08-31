#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define VI vector<int> 
#define ll long long

#define INF 314000000

vector<VI> in[110000];
VI edge[110000];
int can_fin[110000];

VI in1[110000]; int stt[110000];
VI rev[110000];
int cost[110000];
priority_queue<pair<ll,int> > q;

ll mn[110000], mx[110000];

int reached[110000];

int dfs(int now, int tag){
  int i, j, k;
  if(reached[now]==0) return 0;
  reached[now] = tag;
  rep(i,in[now].size()) if(in[now][i][0]){
    REP(j,1,in[now][i].size()){
      if(mx[in[now][i][j]]==-2 || reached[in[now][i][j]]==tag){ mx[now] = -2; return 1; }
      if(dfs(in[now][i][j], tag)){ mx[now] = -2; return 1; }
    }
  }
  reached[now] = 0;
  return 0;
}

int solve(int now){
  int i, j, k;
  ll c = 0, tmp;

  if(mx[now] != -3) return mx[now];

  rep(i,in[now].size()) if(in[now][i][0]){
    tmp = in[now][i][0];
    REP(j,1,in[now][i].size()){
      tmp += solve(in[now][i][j]);
      if(tmp > INF) tmp = INF;
    }
    if(tmp > INF) tmp = INF;
    if(c < tmp) c = tmp;
  }

  return mx[now] = c;
}

int main(){
  int i,j,k,l,m,n;
  ll c;

  scanf("%d%d",&m,&n);
  while(m--){
    VI add;
    scanf("%d%d",&i,&k);
    add.push_back(0);
    while(k--){
      scanf("%d",&j);
      if(j<0) add[0]++;
      else    add.push_back(j-1);
    }
    in[i-1].push_back(add);
  }

//  rep(i,n) rep(j,edge[i].size()) printf("%d -> %d\n",i,edge[i][j]);

  rep(i,n) can_fin[i] = 0;

  m = 0;
  rep(i,n) rep(j,in[i].size()) in1[m] = in[i][j], stt[m] = i, m++;

  rep(i,m){
    REP(j,1,in1[i].size()) cost[i]++, rev[in1[i][j]].push_back(i);
  }

  rep(i,n) mn[i] = INF * (ll)INF;
  rep(i,m) if(cost[i]==0){
    c = in1[i][0];
    REP(j,1,in1[i].size()) c += mn[in1[i][j]];
    if(c > INF) c = INF;
    if(mn[stt[i]] > c){
      mn[stt[i]] = c;
      q.push(make_pair(-c,i));
    }
  }

  while(q.size()){
    i = q.top().second; q.pop();
    k = stt[i];
    if(can_fin[k]) continue;
    can_fin[k] = 1;

    rep(i,rev[k].size()){
      cost[rev[k][i]]--;
      if(cost[rev[k][i]]==0){
        l = rev[k][i];
        c = in1[l][0];
        REP(j,1,in1[l].size()) c += mn[in1[l][j]];
        if(c > INF) c = INF;
        if(mn[stt[l]] > c){
          mn[stt[l]] = c;
          q.push(make_pair(-c,l));
        }
      }
    }
  }

//  rep(i,n) printf("can_fin [%d] = %d\n",i,can_fin[i]);

  rep(i,n){
    mx[i] = -3;
    if(can_fin[i]==0) mn[i] = mx[i] = -1;
  }

  rep(i,n) rep(j,in[i].size()){
    int ok = 1;
    REP(k,1,in[i][j].size()) if(can_fin[in[i][j][k]]==0) ok = 0;
    if(!ok) in[i][j][0] = 0;
  }

/*  rep(i,n) rep(j,in[i].size()) if(in[i][j][0]){
    REP(k,1,in[i][j].size()) edge[i].push_back(in[i][j][k]);
  }*/

  rep(i,n) reached[i] = -1;
  rep(i,n) if(can_fin[i] && reached[i]==-1){
    if(dfs(i, i+1)) mx[i] = -2;
  }

  rep(i,n) if(can_fin[i] && mx[i] == -3) solve(i);

  rep(i,n) printf("%d %d\n",(int)mn[i],(int)mx[i]);

  return 0;
}