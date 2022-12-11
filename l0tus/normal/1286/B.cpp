#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int N,p,c,r,par[MN],val[MN],ans[MN];
bool ch;
vector<int> T[MN];
vector<int> O[MN];

void dfs(int s)
{
    if(ch) return;
    if(O[s].size()==val[s]) O[s].push_back(s);
    for(int i=0; i<T[s].size(); i++){
        dfs(T[s][i]);
        for(int x : O[T[s][i]]){
            O[s].push_back(x);
            if(O[s].size()==val[s]) O[s].push_back(s);
        }
    }
    if(O[s].size()<val[s]) ch = 1;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> p >> c;
        if(p==0) r = i;
        par[i] = p;
        T[p].push_back(i);
        val[i] = c;
    }
    dfs(r);
    if(ch){
        cout << "NO";
        return 0;
    }
    for(int i=0; i<N; i++){
        ans[O[r][i]] = i+1;
    }
    cout << "YES\n";
    for(int i=1; i<=N; i++) cout << ans[i] << ' ';
}