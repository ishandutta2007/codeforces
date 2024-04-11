#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int N,K,D,E,vis[MN],ans;
vector<int> V[MN];

void DFS(int cur)
{
    vis[cur] = 1;
    for(int x : V[cur]){
        if(!vis[x]) DFS(x);
    }
}

int main()
{
    cin >> N >> K;
    ans = N;
    for(int i=0; i<K; i++){
        cin >> D >> E;
        V[D].push_back(E);
        V[E].push_back(D);
    }
    for(int i=1; i<=N; i++){
        if(!vis[i]){
            DFS(i);
            ans--;
        }
    }
    cout << K-ans;
}