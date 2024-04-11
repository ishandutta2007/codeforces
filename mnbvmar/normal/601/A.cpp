#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).begin())

/////////////////////////////////////////////////////////

const int MaxN = 405;

int N, M;
bool isTrain[MaxN][MaxN];


void input(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    isTrain[u][v] = isTrain[v][u] = true;
  }
    
}


const int Infty = 10101010;
int tdist[2][MaxN];

int main(){
  input();

  int ta = 0, tb = 0;
  for(int i = 1; i <= N; i++){
    if(isTrain[1][i]) ta++;
    if(isTrain[N][i]) tb++;
  }
  debug(ta, tb);

  
  if(ta == 0 || ta == N-1 || tb == 0 || tb == N-1){
    cout << -1 << endl;
    return 0;
  }

  int res = 0;
  for(int zz = 0; zz < 2; zz++){
    fill(tdist[zz], tdist[zz]+N+1, Infty);
    tdist[zz][1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
      int v = Q.front(); Q.pop();
      debug(zz, v);
      for(int i = 1; i <= N; i++){
        if(i == v) continue;
        if(isTrain[i][v] != zz) continue;
        if(tdist[zz][i] == Infty){
          tdist[zz][i] = tdist[zz][v] + 1;
          Q.push(i);
        }
      }
    }

    if(tdist[zz][N] == Infty){
      cout << -1 << endl;
      return 0;
    }
    res = max(res, tdist[zz][N]);
  }  

  cout << res << endl;
}