#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> edges[110000];

pair<int,int> blocks[110000];

vector<int> l;

void dfs(int a, int par){
    blocks[a].first = l.size();
    l.push_back(a);
    for(int v : edges[a]){
        if(v != par){
            dfs(v, a);
        }
    }
    blocks[a].second = l.size()-1;
}
int n, m;
int s;
int groups;

int b;

int cnt[110000];

int minv[1000];
int minc[1000]; // count
int lazy[1000];

int zeroes[110000];

void upd(int a, int b, int val){
    int k = a/s;
    if(k == b/s){
        if(a + (s-1) == b){
            minv[k] += val;
            lazy[k] += val;
        } else {
            for(int j = a; j <= b; j++){
                cnt[j] += val;
            }
            for(int j = s*k; j < s*(k+1) && j < n; j++){
                cnt[j] += lazy[k];
            }
            lazy[k] = 0;

            minv[k] = cnt[s*k];
            for(int j = s*k; j < s*(k+1) && j < n; j++){
                minv[k] = min(minv[k], cnt[j]);
            }
            minc[k] = 0;
            for(int j = s*k; j < s*(k+1) && j < n; j++){
                if(cnt[j] == minv[k]) minc[k]++;
            }
        }
        return;
    }
    upd(a, (a/s + 1) * s - 1, val);
    upd((a/s+1) * s, b, val);
    return;
}

int numzero(){
    int ans = 0;
    for(int j = 0; j < groups; j++){
        if(minv[j] == 0){
            ans += minc[j];
        }
    }
    return ans;
}

vector<pair<int,int> > intervals[110000];
vector<pair<int,int> > actions[110000]; // before
int main(){
    scanf("%d%d", &n, &m);
    s = sqrt(n) + 1;
    groups = (n-1)/s + 1;
    for(int i = 0; i < n; i++){
        cnt[i] = zeroes[i] = 0;
    }
    for(int i = 0; i < groups; i++){
        minv[i] = 0;
        lazy[i] = 0;
        minc[i] = min(s, n-i*s);
    }

    for(int j = 0; j < n-1; j++){
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    dfs(0, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        pair<LL,LL> da = blocks[a];
        pair<LL,LL> db = blocks[b];
        if(a == 0 || b == 0){
        }
        if(da.second < db.first){
            intervals[i].push_back(da);
            intervals[i].push_back(db);
        } else if(db.second < da.first){
            intervals[i].push_back(db);
            intervals[i].push_back(da);
        } else if(db.second <= da.second && db.first >= da.first){
            intervals[i].push_back(da);
        } else {
            intervals[i].push_back(db);
        }
        for(int j = 0; j < intervals[i].size(); j++){
            actions[intervals[i][j].first].push_back(make_pair(i,1));
            actions[intervals[i][j].second+1].push_back(make_pair(i,-1));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < actions[i].size(); j++){
            int v = actions[i][j].first;
            for(int k = 0; k < intervals[v].size(); k++){
                upd(intervals[v][k].first, intervals[v][k].second, actions[i][j].second);
            }
        }
        zeroes[l[i]] = numzero();
    }
    for(int j = 0; j < n; j++){
        printf("%d ", max(0,n-1-zeroes[j]) );
    }
    printf("\n");
}