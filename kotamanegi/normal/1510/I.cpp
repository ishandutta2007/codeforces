#include "bits/stdc++.h"
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
#define ld long double
ld prob[20000];
ld die_prob[20000];
int cnter[20000];
int n,m;
ld Winning_prob[20000];
int real_ans = 0;
string read_predict(){
  Winning_prob[0] = 1;
  string s;
#ifdef DEBUG
  real_ans = rand() % 2;
  int x = real_ans;
  REP(i,n){
    float hoge = (float)(rand()) / ((float)(RAND_MAX));
    if(hoge >= Winning_prob[i]){
      s.push_back((x^1) + '0');
    }else{
      s.push_back((x)+'0');
    }
  }
  cout << s << endl;
  cout << real_ans << endl;
#else
  cin >> s;
#endif
  return s;
}
int receive_score(int x){
  cout << x << endl;
  int y = real_ans;
#ifndef DEBUG
  cin >> y;
#endif
  return y;
}
void solve(){
#ifdef DEBUG
  n = 1000;
  m = 10000;
#else
  cin >> n >> m;
#endif
  int penalty = 0;
  REP(i,n){
    prob[i] = 1;
    die_prob[i] = 0;
    Winning_prob[i] = 0.0 + (float)(rand()) / ((float)(10.0 * RAND_MAX));;
  }
  REP(q,m){
    string s = read_predict();
    ld percent[2] = {};
    for(int i = 0;i < s.length();++i){
      percent[s[i] - '0'] += prob[i];//* prob[i] * prob[i];
      percent[(s[i] - '0') ^ 1] += die_prob[i];//* die_prob[i] * die_prob[i];
    }
    int hoge;
    if(percent[0] < percent[1]){
      hoge = receive_score(1);
      if(hoge != 1) penalty++;
    }else{
      hoge = receive_score(0);
      if(hoge != 0) penalty++;
    }
    for(int i = 0;i < s.length();++i){
      if(s[i] != '0' + hoge){
        cnter[i]++;
        die_prob[i] += prob[i] * 0.20L;
        prob[i] *= 0.80L;
      }else{
        prob[i] += die_prob[i] * 0.20L;
        die_prob[i] *= 0.80L;
      }
    }
  }
  int hoge = 1e9;
  REP(i,n){
    hoge = min(hoge,cnter[i]);
  }
#ifdef DEBUG
  if((double)hoge * 1.3 + 100 < penalty){
    throw runtime_error("Wrong Answer!");
  }
#endif
}
int main(){
  srand(time(NULL));
  int t = 1;
  REP(tea,t){
    solve();
  }
}