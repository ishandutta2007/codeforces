#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e3+5;
int deg[MN],A,B,C,D;
bool ch[MN];
vector<int> T[MN];

bool dfs(int s, int r)
{
    if(s==B) return 1;
    for(int e:T[s]){
        if(ch[e]||e==r) continue;
        if(dfs(e,s)){
            if(s==A) B = e;
            return 1;
        }
    }
    return 0;
}

void solve(int s, int r)
{
    ch[s] = 1;
    for(int e:T[s]){
        if(ch[e]||e==r) continue;
        solve(e,s);
    }
}

void act(int s)
{
    ch[s] = 1;
    for(int e:T[s]){
        if(ch[e]) continue;
        deg[e]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<N; i++){
        int u,v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i=1; i<=N/2; i++){
        A = B = 0;
        for(int j=1; j<=N; j++){
            if(ch[j]) continue;
            if(deg[j]==1){
                if(A) B = j;
                else A = j;
            }
        }
        if(A==0||B==0) break;
        cout << "? " << A << ' ' << B << '\n';
        cout.flush();
        cin >> C;
        if(C==B) swap(A,B);
        if(C==A){
            dfs(A,A);
            solve(B,A);
            deg[A]--;
        }
        else{
            act(A);
            act(B);
        }
    }
    for(int i=1; i<=N; i++){
        if(ch[i]) continue;
        cout << "! " << i;
        break;
    }
}