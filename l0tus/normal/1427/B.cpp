#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int main()
{
   #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
   #endif
   
    ios_base::sync_with_stdio(0),cin.tie(0);

    int T;
    cin >> T;
    while(T--){
      int N,K;
      string S;
      cin >> N >> K >> S;
      int A=0;
      int ans = 0, prv = -INF;
      bool ch = 0;
      vector<int> V;
      for(int i=0; i<N; i++){
         if(S[i]=='W'){
            ch = 1;
            if(prv==i-1) ans+=2;
            else{
               V.push_back(i-1-prv);
               ans++;
            }
            prv = i;
         }
         else A++;
      }
      sort(all(V));
      if(K==0) ans = ans; 
      else if(!ch) ans = 2*K-1;
      else if(A<K) ans = 2*N-1;
      else{
         ans += 2*K;
         for(int x:V){
            if(K>=x){
               K-=x;
               ans++;
            }
         }
      }
      cout << ans << '\n';
   }
}