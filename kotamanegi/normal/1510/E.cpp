#include "bits/stdc++.h"
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
#define ld long double
typedef struct Data{
  int x;
  int y;
  string correspond;
}Data;
vector<Data> mae[2000][30];
vector<Data> usiro[2000][30];
void solve(){
  int n;
  ld a,b;
  cin >> n >> a >> b;
  vector<int> inputs;
  int bunkatu = n/2;
  REP(i,(1 << bunkatu)){
    int ok = 1;
    int now_itr = 0;
    int sum_x[2] = {};
    int sum_y = 0;
    int plates = 0;
    string now;
    REP(q,bunkatu){
      if((1 << q) & i){
        now.push_back('(');
      }else{
        now.push_back(')');
      }
    }
    REP(q,now.size()){
      if(now[q] == '('){
        sum_x[0] += 3 * q + 2;
        sum_x[0] += now_itr * (2 * (3*q) + 3);
        sum_x[1] += 3 * (n-q-1) + 1;
        sum_x[1] += now_itr * (2 * (3*(n-q-1)) + 3);
        sum_y += (3 * now_itr + 1);
        sum_y += 3 * (now_itr * now_itr);
        plates += now_itr * 2+ 1;
        now_itr++;
      }else{
        now_itr--;
        if(now_itr < 0){
          ok = 0;
          break;
        }
        sum_x[0] += 3 * q + 1;
        sum_x[0] += now_itr * (2 * (3*q) + 3);
        sum_x[1] += 3 * (n-q-1) + 2;
        sum_x[1] += now_itr * (2 * (3 * (n - q - 1)) + 3);
        sum_y += (3 * now_itr + 1);
        sum_y += 3 * (now_itr * now_itr);
        plates += now_itr * 2 + 1;
      }
    }
    if(ok == 0) continue;
    mae[plates][now_itr].push_back(Data{sum_x[0],sum_y,now});
    reverse(now.begin(),now.end());
    REP(i,now.size()){
      if(now[i] == '('){
        now[i] = ')';
      }else{
        now[i] = '(';
      }
    }
    usiro[plates][now_itr].push_back(Data{sum_x[1],sum_y,now});
  }
  for(int i = 1;i < 2000;++i){
    ld Req_X = a * (ld) i * 3.0L;
    ld Req_Y = b * (ld) i * 3.0L;
    int X = round(Req_X);
    int Y = round(Req_Y);
    if(abs(Req_X - (ld)X) > 5e-7L or abs(Req_Y - (ld)Y) > 5e-7L) continue;
    for(int meet_point = 0;meet_point < n/2+1;++meet_point){
      for(int q = 0;q <= i;++q){
        int j = i - q;
        if(mae[q][meet_point].size() == 0 or usiro[j][meet_point].size() == 0) continue;
        //sort(mae[q][meet_point].begin(),mae[q][])
        map<int,vector<Data>> gogo;
        for(auto y:usiro[j][meet_point]){
          gogo[y.x].push_back(y);
        }
        for(auto x:mae[q][meet_point]){
          if(X - x.x < 0) continue;
          for(auto y:gogo[X - x.x]){
            if(x.x + y.x == X and x.y + y.y == Y){
              cout << x.correspond << y.correspond << endl;
              return;
            }
          }
        }
      }
    }
  }
}
int main(){
  srand(time(NULL));
  int t = 1;
  REP(tea,t){
    solve();
  }
}