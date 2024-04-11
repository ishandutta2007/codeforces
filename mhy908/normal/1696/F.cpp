#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n;
vector<pii> ans;

bool arr[110][110][110], ch[110], flg, flg2;
int col[110];
vector<vector<int> > lv[110];

vector<int> link[110];
bool ch2[110];
int dis[110], que[110], fr, re;

bool check(){
    if(ans.size()!=n-1)return false;
    for(int i=1; i<=n; i++)link[i].clear();
    for(auto i:ans){
        link[i.F].eb(i.S);
        link[i.S].eb(i.F);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)ch2[j]=false;
        for(int j=1; j<=n; j++)dis[j]=0;
        re=0;
        ch2[i]=true;
        que[++re]=i;
        for(fr=1; fr<=re; fr++){
            for(auto j:link[que[fr]]){
                if(ch2[j])continue;
                ch2[j]=true;
                dis[j]=dis[que[fr]]+1;
                que[++re]=j;
            }
        }
        for(int j=1; j<=n; j++)ch2[j]=false;
        for(auto j:lv[i]){
            int nd=dis[j[0]];
            if(ch2[nd])return false;
            ch2[nd]=true;
            for(auto k:j){
                if(nd!=dis[k])return false;
            }
        }
    }
    return true;
}

void dfs(int nw, int num, int c){
    col[num]=c;
    for(int i=1; i<=n; i++){
        if(!arr[nw][num][i])continue;
        if(col[i]==0)dfs(nw, i, c);
        if(col[i]!=c)flg=true;
    }
}

void dfs2(int num, int par){
    if(par!=n+1)ans.eb(num, par);
    ch[num]=true;
    for(auto i:lv[num]){
        if(binary_search(all(i), par)){
            for(auto j:i){
                if(j==par)continue;
                if(ch[j])flg2=true;
                else dfs2(j, num);
            }
            break;
        }
    }
}

void solve(){
    scanf("%d", &n);
    flg=false;

    for(int i=1; i<n; i++){
        for(int j=1; i+j<=n; j++){
            for(int k=1; k<=n; k++){
                char c;
                scanf(" %c", &c);
                if(c=='1')arr[k][i][i+j]=arr[k][i+j][i]=true;
                else arr[k][i][i+j]=arr[k][i+j][i]=false;
                if((k==i||k==i+j)&&c=='1')flg=true;
            }
        }
    }
    if(flg){
        for(int i=1; i<=n; i++)lv[i].clear();
        puts("No");
        return;
    }

    for(int i=1; i<=n; i++){
        int cnum=0;
        for(int j=1; j<=n; j++){
            if(col[j]||i==j)continue;
            dfs(i, j, ++cnum);
        }
        for(int j=1; j<n; j++){
            for(int k=j+1; k<=n; k++){
                if(arr[i][j][k]&&col[j]!=col[k])flg=true;
                if(arr[i][j][k]==0&&col[j]==col[k])flg=true;
            }
        }
        lv[i].resize(cnum);
        for(int j=1; j<=n; j++){
            if(i==j)continue;
            lv[i][col[j]-1].eb(j);
            col[j]=0;
        }
    }
    if(flg){
        for(int i=1; i<=n; i++)lv[i].clear();
        puts("No");
        return;
    }
    /*for(int i=1; i<=n; i++){
        printf("%d : ", i);
        for(auto j:lv[i]){
            printf("{ ");
            for(auto k:j)printf("%d ", k);
            printf("} ");
        }
        printf("\n");
    }*/
    for(int i=0; i<lv[1].size(); i++){
        for(int j=1; j<=n; j++)ch[j]=false;
        flg2=false;
        ans.clear();
        lv[1][i].eb(n+1);
        dfs2(1, n+1);
        lv[1][i].pop_back();
        if(!flg2&&check()){
            for(int j=1; j<=n; j++)lv[j].clear();
            puts("Yes");
            for(auto j:ans)printf("%d %d\n", j.F, j.S);
            return;
        }
    }
    for(int i=1; i<=n; i++)lv[i].clear();
    puts("No");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}