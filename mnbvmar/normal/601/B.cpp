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



const int MaxN = 100005;

int fuParent[MaxN], fuRank[MaxN], fuSize[MaxN];

void fu_init(int L, int R){
  iota(fuParent+L, fuParent+R+1, L);
  fill(fuRank+L, fuRank+R+1, 0);
  fill(fuSize+L, fuSize+R+1, 1);
}

int fu_find(int x){
  if(x == fuParent[x]) return x;
  return (fuParent[x] = fu_find(fuParent[x]));
}

void fu_union(int a, int b){
  a = fu_find(a);
  b = fu_find(b);
  if(a == b) return;

  if(fuRank[a] > fuRank[b]) swap(a, b);
  fuParent[a] = b;
  fuRank[b]++;
  fuSize[b] += fuSize[a];
}


int N, Q;
int tab[MaxN];
int diff[MaxN];
int order[MaxN];

int numSorted[MaxN];

void input(){
  ios_base::sync_with_stdio(0);
  cin >> N >> Q;
  for(int i = 1; i <= N; i++){
    cin >> tab[i];
  }
  for(int i = 1; i < N; i++){
    diff[i] = abs(tab[i+1] - tab[i]);
    debug(i, diff[i]);
  }


  iota(numSorted, numSorted+N-1, 1);
  sort(numSorted, numSorted+N-1, [&](int lhs, int rhs){
        return diff[lhs] < diff[rhs];
      });
  for(int v = 0; v < N-1; v++){
    order[numSorted[v]] = v;
    debug(numSorted[v]);
  }
}

int main(){
  input();
  for(int query = 1; query <= Q; query++){
    int L, R;
    cin >> L >> R;
    R--;

    LL result = 0;
    fu_init(L, R+1);

    for(int i = 0; i < N-1; i++){
      int id = numSorted[i];
      if(id >= L && id <= R){
        debug(query, id);
        LL lcount = 1, rcount = 1;
        int LLL = id, RR = id;

        if(id > L && order[id] > order[id-1]){
          LLL = fu_find(id-1);
          lcount += fuSize[LLL];
        }
        if(id < R && order[id] > order[id+1]){
          RR = fu_find(id+1);
          rcount += fuSize[RR];
        }
        debug(lcount, rcount);

        result += lcount * rcount * diff[id];
        fu_union(id, LLL);
        fu_union(id, RR);
      }
    }
    cout << result << endl;
  }
}