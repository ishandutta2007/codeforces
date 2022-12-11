#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 3e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int pos[MN],d[MN],A[MN];

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
        for(int i=1; i<=N; i++){
            cin >> A[i];
            d[A[i]] = max(d[A[i]],i-pos[A[i]]);
            pos[A[i]] = i;
        }
        vector<pii> V;
        for(int i=1; i<=N; i++){
            if(d[A[i]]){
                d[A[i]] = max(d[A[i]],N+1-pos[A[i]]);
                V.emplace_back(d[A[i]],A[i]);
                d[A[i]] = 0;
                pos[A[i]] = 0;
            }
        }
        sort(all(V));
        int x = -1, tmp = INF;
        for(int i=1; i<=N; i++){
            while(x+1<V.size()&&V[x+1].va<=i){
                tmp = min(tmp,V[x+1].vb);
                x++;
            }
            if(tmp==INF) cout << -1 << ' ';
            else cout << tmp << ' ';
        }
        cout << '\n';
    }
}