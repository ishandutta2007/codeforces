#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> edges[110000];

int num;
int vs[110000];
int ps[110000];
int t = 0;
void dfs(int v, int p){
    for(int a : edges[v]){
        if(a == p) continue;
        dfs(a, v);
    }
    vs[t] = v;
    ps[t] = p;
    t++;
}

int m1[110000];
int m2[110000];

int solve(int k){
    for(int i = 0; i < t; i++){
        m1[i] = m2[i] = 0;
    }
    int ans = 0;
    for(int i = 0; i < t; i++){
        int v = vs[i];
        int p = ps[i];
        if(m1[v] + m2[v] + 1 >= k){
            ans++;
        } else {
            if(v && m1[v] + 1 > m2[p]) m2[p] = m1[v] + 1;
            if(v && m2[p] > m1[p]) swap(m1[p], m2[p]);
        }
    }
    return ans;
}

vector<int> answers;
void compute(int x, int y, int minv, int maxv){
    if(x > y) return;
    int m = (x + y) / 2;
    if(minv == maxv){
        answers[m] = minv;
    } else {
        answers[m] = solve(m);
    }
    compute(x, m-1, answers[m], maxv);
    compute(m+1, y, minv, answers[m]);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs(0, -1);
    
    const int C = 1000;
    answers.resize(n+1, 0);
    for(int i = 1; i <= C && i <= n; i++){
        answers[i] = solve(i);
    }
    if(C < answers.size()) compute(C+1, n, 0, answers[C]);
    for(int i = 1; i <= n; i++){
        cout << answers[i] << '\n';
    }
}