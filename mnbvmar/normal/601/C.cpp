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


const int MaxN = 105,
          MaxM = 1005;

long double probab[MaxN][MaxN*MaxM];
int N, M;
int discard[MaxN];
int total = 0;

void input(){
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> discard[i];
    total += discard[i];
  }
}

int main(){
  input();
  cout << fixed << setprecision(12);
  probab[0][0] = 1;

  if(M == 1){
    cout << 1. << endl;
    return 0;
  }

  for(int disc = 1; disc <= N; disc++){
    int without = discard[disc-1];

    probab[disc][0] = 0;
    long double prefSum = 0;

    for(int tot = 1; tot <= N*M; tot++){
      prefSum += probab[disc-1][tot-1];
      if(tot > M){
        prefSum -= probab[disc-1][tot-M-1];
      }

      long double cur = prefSum;
      if(tot >= without) cur -= probab[disc-1][tot-without];
      probab[disc][tot] = (long double)(1)/(M-1) * cur;
    }
  }

  long double pref = 0;
  for(int i = 0; i < total; i++){
    pref += probab[N][i];
  }

  cout << 1 + pref * (M-1) << endl;
}