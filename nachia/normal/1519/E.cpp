#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using ll = long long;
using ull = unsigned long long;
using namespace std;

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;

ull GCD(ull a,ull b){ return b ? GCD(b,a%b) : a; }

map<pair<ull,ull>,int> Lines;

struct Edge{ int to, id; };

int N;
vector<vector<Edge>> E;
vector<vector<Edge>> E2;
vector<pair<int,int>> ans;


void solve_input();
void solve_convert_graph();
void solve_final();


void solve_input(){
  cin>>N;
  for(int i=0; i<N; i++){
    unsigned int a,b,c,d; cin>>a>>b>>c>>d;
    ull A1 = (ull)(a+b)*d, B1 = (ull)b*c;
    ull g1 = GCD(A1,B1); A1/=g1; B1/=g1;
    int j1 = Lines[make_pair(A1,B1)];
    if(j1 == 0){
      j1 = Lines[make_pair(A1,B1)] = E.size()+1;
      E.push_back({});
    }
    j1--;
    ull A2 = (ull)a*d, B2 = (ull)b*(c+d);
    ull g2 = GCD(A2,B2); A2/=g2; B2/=g2;
    int j2 = Lines[make_pair(A2,B2)];
    if(j2 == 0){
      j2 = Lines[make_pair(A2,B2)] = E.size()+1;
      E.push_back({});
    }
    j2--;
    E[j1].push_back({j2,i});
    E[j2].push_back({j1,i});
  }
  Lines.clear();
}

void solve_convert_graph(){
  vector<int> F(N,0);
  vector<int> FV(E.size(),0);
  E2.resize(E.size());
  queue<int> Q;
  vector<int> IV(E.size());
  for(int s=0; s<E.size(); s++) if(FV[s] == 0){
    FV[s] = 1;
    Q.push(s);
    while(Q.size()){
      int p = Q.front(); Q.pop();
      for(Edge e : E[p]) if(F[e.id] == 0){
        F[e.id] = 1;
        if(FV[e.to] == 0){
          FV[e.to] = 1;
          Q.push(e.to);
          E2[p].push_back({e.to,e.id});
          E2[e.to].push_back({p,e.id});
        }
        else{
          E2[p].push_back({(int)E2.size(),e.id});
          E2.push_back({});
          E2.back().push_back({p,e.id});
        }
      }
    }
  }
}

void solve_final(){
  int N2 = E2.size();
  vector<int> I;
  queue<int> Q;
  vector<int> F(N2,0);
  vector<int> P(N2,-1);
  
  vector<int> F2(N,0);

  for(int s=0; s<N2; s++) if(F[s] == 0){
    F[s] = 1;
    Q.push(s);
    while(Q.size()){
      int p = Q.front(); Q.pop();
      I.push_back(p);
      for(Edge e : E2[p]) if(F[e.to] == 0){
        F[e.to] = 1;
        P[e.to] = e.id;
        Q.push(e.to);
      }
    }

    for(int i=I.size()-1; i>=0; i--){
      int p = I[i];
      int waitingEdge = -1;
      for(Edge e : E2[p]) if(e.id != P[p]) if(F2[e.id] == 0){
        if(waitingEdge == -1){ waitingEdge = e.id; continue; }
        F2[waitingEdge] = F2[e.id] = 1;
        ans.push_back(make_pair(waitingEdge,e.id));
        waitingEdge = -1;
      }
      if(i != 0 && waitingEdge != -1){
        F2[waitingEdge] = F2[P[p]] = 1;
        ans.push_back(make_pair(waitingEdge,P[p]));
        waitingEdge = -1;
      }
    }

    I.clear();
  }
}

void solve(){
  solve_input();
  solve_convert_graph();
  solve_final();

  cout << ans.size() << "\n";
  for(auto a : ans){
    cout << (a.first+1) << " " << (a.second+1) << "\n";
  }
}

int main(){
  solve();
  return 0;
}