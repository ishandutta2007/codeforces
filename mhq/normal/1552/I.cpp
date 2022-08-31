//from codeforces 150 round E
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sub(int a, int b) {
    int s = a - b;
    s %= mod;
    if (s < 0) s += mod;
    return s;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
#define pb push_back

const int N=105;
const int M=N*N;

int type[M];//0 - leaf, 1 - P, 2 - Q
vector<int> go[M];
int tsz,root;
int color[M];//1 - white, 3 - grey, 2 - black

void init(int n){
    if(n==1){
        root=tsz=1;
    }else{
        root=tsz=n+1;
        type[root]=1;
        for(int i=1;i<=n;i++)go[root].pb(i);
    }
}

char *s;
void Paint(int u){
    if(type[u]==0){//leaf
        color[u]=s[u]=='1'?2:1;
    }else{
        color[u]=0;
        for(int v:go[u]){
            Paint(v);
            color[u]|=color[v];
        }
    }
}

int Merge(vector<int> nodes){
    if(nodes.empty())return 0;
    if(nodes.size()==1)return nodes[0];
    int node=++tsz;
    type[node]=1;
    go[node]=nodes;
    return node;
}

bool ok=true;
int Solve(int u,int t){
    if(!ok)return 0;
    if(color[u]!=3)return u;
    vector<int> ch[3];
    for(int v:go[u])ch[color[v]-1].pb(v);
    if(ch[2].size()>2||(t>0&&ch[2].size()>1)){ok=false;return 0;}
    if(type[u]==1){//P
        if(t==0){
            go[u]=ch[0];
            if(ch[2].size()==2||(ch[2].size()>0&&ch[1].size()>0)){
                int Q=Solve(ch[2][0],1);
                if(!ok)return 0;
                int b=Merge(ch[1]);
                if(b)go[Q].pb(b);
                if(ch[2].size()>1){
                    int q=Solve(ch[2][1],2);
                    if(!ok)return 0;
                    for(int v:go[q])go[Q].pb(v);
                }
                go[u].pb(Q);
            }else if(ch[2].size()==1){
                int Q=Solve(ch[2][0],0);
                if(!ok)return 0;
                go[u].pb(Q);
            }else{
                int b=Merge(ch[1]);
                if(b)go[u].pb(b);
            }
        }else{
            type[u]=2;
            go[u].clear();
            int w=Merge(ch[0]);
            if(w)go[u].pb(w);
            if(ch[2].size()){
                int g=Solve(ch[2][0],1);
                if(!ok)return 0;
                for(int v:go[g])go[u].pb(v);
            }
            int b=Merge(ch[1]);
            if(b)go[u].pb(b);
            if(t==2)reverse(go[u].begin(),go[u].end());
        }
        if(go[u].size()==1)return go[u][0];
        return u;
    }else{//Q
        string pattern=t==0?"wgbgw":"wgb";
        int ptr=0;
        if(color[go[u][0]]==2||color[go[u].back()]==1)reverse(go[u].begin(),go[u].end());
        vector<int> ngo;
        /*printf("Q %i: ",u);
        for(int v:go[u]){
            char col=color[v]==1?'w':color[v]==2?'b':'g';
            printf("%c ",col);
        }
        printf("\n");*/
        bool strict=t!=0||ch[2].size()>1||(ch[2].size()>0&&ch[1].size()>0);
        for(int v:go[u]){
            char col=color[v]==1?'w':color[v]==2?'b':'g';
            while(ptr<pattern.size()&&pattern[ptr]!=col)ptr++;
            if(ptr==pattern.size()){ok=false;return 0;}
            if(color[v]!=3){//white or black
                ngo.pb(v);
            }else{//grey
                int Q;
                if(!strict)Q=Solve(v,0);
                else if(ptr==1)Q=Solve(v,1);
                else Q=Solve(v,2);
                if(!ok)return 0;
                if(!strict)ngo.pb(Q);
                else for(int h:go[Q])ngo.pb(h);
                ptr++;
            }
        }
        go[u]=ngo;
        if(t==2)reverse(go[u].begin(),go[u].end());
        return u;
    }
}

void AddSet(char *t){
    if(!ok)return;
    s=t;
    Paint(root);
    root=Solve(root,0);
}

void Print(int u){
    if(type[u]==0){
        printf("%i ",u);
    }else{
        if(type[u]==1){
            printf("P{ ");
        }else printf("Q[ ");
        for(int v:go[u])Print(v);
        if(type[u]==1){
            printf("} ");
        }else printf("] ");
    }
}

vector<int> ord;
int ANS = 1;
char mat[N][N];
int fact[N];
void DFS(int u){
    if(type[u]==0){
        ord.pb(u);
    }else{
        if (type[u] == 1) ANS = mult(ANS, fact[go[u].size()]);
        else ANS = mult(ANS, 2);
        for(int v:go[u])DFS(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout <<1 << '\n';
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mult(i, fact[i - 1]);
    init(n);
    for (int i = 1; i <= m; i++) {
        int sz;
        cin >> sz;
        for (int j = 1; j <= n; j++) mat[i][j] = '0';
        for (int j = 1; j <= sz; j++) {
            int x;
            cin >> x;
            mat[i][x] = '1';
        }
        AddSet(mat[i]);
    }
    if (!ok) {
        cout << 0 << '\n';
    }
    else {
        DFS(root);
        cout << ANS << '\n';
       /* for (int i = 0; i < M; i++) {
            if (type[i] != 0) {
                int c = go[i].size();
                assert(c >= 2);
                if (type[i] == 1) ans = mult(ans, fact[c]);
                else ans = mult(ans, 2);
            }
        }
        cout << ans << '\n';*/
    }

    return 0;
}