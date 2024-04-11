#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

#define wait system("pause")
#define MP make_pair

using namespace std;

const int MAXN = (int)2e6 + 10;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

int V[MAXN];
int T[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; ++i){
        cin >> V[i];
        V[n + i] = V[i];
    }
        
    while (q--)
    {
          int v; cin >> v;
          
          
          pii pos = MP(MAXN, -1);
          
          for (int i = 0, j = 0, val = 0; i < n; ++i)
          {
              while (j <= i + n && val <= v){
                    val += V[j++];
              }
              T[i] = j - i - 1;
              //cout << T[i] << " ";
              pos = min(pos, MP(T[i], i));
              val -= V[i];
          }
          //cout << endl;
          
          int ans = MAXN;
          for (int i = pos.second; i <= pos.second + pos.first; ++i)
          {
              int t = 0, j = i, cur_ans = 0;
              while (t < n)
              {
                    t += T[j];
                    j += T[j];
                    if (j >= n) j -= n;
                    ++cur_ans;
              }
              ans = min(ans, cur_ans);
          }
          cout << ans << endl;
    }
    
    //wait;
}
/*
6 3
2 4 2 1 3 2
7
*/