#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int node;
int edge[120][120];
int type[120];

ll x[120], y[120];
int border[120], space[120];
int solved[120];

void solve(int now){
  int i,j,k;
  ll sum=0, mx=0, ele=0;

  if(solved[now]) return;
  solved[now] = 1;

  if(type[now] < 0) return;

  if(type[now]==0){
    rep(i,node) rep(j,edge[now][i]){
      ele++;
      solve(i);
      sum += x[i];
      if(mx < y[i]) mx = y[i];
    }

    x[now] = sum + (ele-1)*space[now] + border[now]*2;
    y[now] = mx + border[now]*2;
  }

  if(type[now]==1){
    rep(i,node) rep(j,edge[now][i]){
      ele++;
      solve(i);
      sum += y[i];
      if(mx < x[i]) mx = x[i];
    }

    x[now] = mx + border[now]*2;
    y[now] = sum + (ele-1)*space[now] + border[now]*2;
  }

  if(ele==0){
    x[now] = y[now] = 0;
    return;
  }
}

int main(){
  int i,j,k,l,m,n;
  map<string,int> mp;
  map<string,int>::iterator it;
  char in[1000];

  while(scanf("%d",&n)==1){
    node = 0;
    rep(i,120) rep(j,120) edge[i][j] = 0;
    rep(i,120) border[i] = space[i] = 0;

    mp.clear();

    while(n--){
      scanf("%s",in);
      if(in[0]=='W'){
        scanf("%s",in);
        for(i=0;;i++) if(in[i]=='(') break;
        sscanf(in+i,"(%d,%d)",&j,&k);

        x[node] = j; y[node] = k;
        type[node] = -1;
        in[i] = '\0';
        mp[(string)in] = node;

        node++;
        continue;
      }
      if(in[0]=='V'){
        scanf("%s",in);

        type[node] = 1;
        mp[(string)in] = node;
        node++;
        
        continue;
      }
      if(in[0]=='H'){
        scanf("%s",in);
        
        type[node] = 0;
        mp[(string)in] = node;
        node++;
        
        continue;
      }

      {
        string input = in;
        string name, op, val;

        for(i=0;;i++) if(input[i]=='.') break;
        name = input.substr(0,i);
        input = input.substr(i+1);

        for(i=0;;i++) if(input[i]=='(') break;
        op = input.substr(0,i);
        input = input.substr(i);

        val = input.substr(1,input.size()-2);

        if(op == "pack"){
          edge[mp[name]][mp[val]]++;
          continue;
        }
        if(op == "set_border"){
          border[mp[name]] = atoi(val.c_str());
          continue;
        }
        if(op == "set_spacing"){
          space[mp[name]] = atoi(val.c_str());
          continue;
        }
      }
    }

    rep(i,node) solved[i] = 0;
    rep(i,node) solve(i);

    for(it = mp.begin(); it!=mp.end(); it++){
      k = (*it).second;
      cout << (*it).first << " " << x[k] << " " << y[k] << endl;
    }
  }

  return 0;
}