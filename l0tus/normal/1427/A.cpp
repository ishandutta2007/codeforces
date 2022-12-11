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
      int N;
      cin >> N;
      vector<int> A(N);
      int sum = 0 ;
      for(int i=0; i<N; i++){
         cin >> A[i];
         sum += A[i];
      }
      if(sum){
         cout << "YES\n";
         if(sum<0) sort(all(A));
         else sort(all(A),greater<int>());
         for(int x:A) cout << x << ' ';
         cout << '\n';
      }
      else cout << "NO\n";
   }
}