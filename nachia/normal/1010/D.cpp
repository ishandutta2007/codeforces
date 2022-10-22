#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


struct Node{
  string t;
  int x,y;
};

int N;
vector<Node> V;
vector<int> I;
vector<int> B;
vector<int> X;

int main(){
  cin >> N;
  V.resize(N);
  rep(i,N){
    auto& v = V[i];
    cin >> v.t;
    if(v.t == "IN"){ cin >> v.x; }
    if(v.t == "NOT"){ cin >> v.x; v.x--; }
    if(v.t == "AND"){ cin >> v.x >> v.y; v.x--; v.y--; }
    if(v.t == "OR"){ cin >> v.x >> v.y; v.x--; v.y--; }
    if(v.t == "XOR"){ cin >> v.x >> v.y; v.x--; v.y--; }
  }

  I.push_back(0);
  rep(i,I.size()){
    int p = I[i];
    auto& v = V[p];
    if(v.t == "NOT"){ I.push_back(v.x); }
    if(v.t == "AND"){ I.push_back(v.x); I.push_back(v.y); }
    if(v.t == "OR"){ I.push_back(v.x); I.push_back(v.y); }
    if(v.t == "XOR"){ I.push_back(v.x); I.push_back(v.y); }
  }

  reverse(I.begin(),I.end());
  B.assign(N,0);
  rep(i,I.size()){
    int p = I[i];
    auto& v = V[p];
    if(v.t == "IN"){ B[p] = v.x; }
    if(v.t == "NOT"){ B[p] = 1 ^ B[v.x]; }
    if(v.t == "AND"){ B[p] = B[v.x] & B[v.y]; }
    if(v.t == "OR"){ B[p] = B[v.x] | B[v.y]; }
    if(v.t == "XOR"){ B[p] = B[v.x] ^ B[v.y]; }
  }

  reverse(I.begin(),I.end());
  X.assign(N,0);
  X[0] = 1;
  rep(i,I.size()){
    int p = I[i];
    auto& v = V[p];
    if(X[p] == 0) continue;
    if(v.t == "NOT"){ X[v.x] = 1; }
    if(v.t == "AND"){
      if(B[p] != ((1^B[v.x]) & B[v.y])) X[v.x] = 1;
      if(B[p] != (B[v.x] & (1^B[v.y]))) X[v.y] = 1;
    }
    if(v.t == "OR"){
      if(B[p] != ((1^B[v.x]) | B[v.y])) X[v.x] = 1;
      if(B[p] != (B[v.x] | (1^B[v.y]))) X[v.y] = 1;
    } 
    if(v.t == "XOR"){
      X[v.x] =  X[v.y] = 1;
    } 
  }

  rep(i,N) if(V[i].t == "IN") cout << (B[0]^X[i]);
  cout << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;