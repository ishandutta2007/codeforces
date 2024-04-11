#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;
struct seg{
    int l, r;
    bool operator < (const seg & x) const{
        return l < x.l;
    }
    void read(){
        scanf("%d %d", &l, &r);
    }
}a[nax];
int n, cnt;
vector<int> b[nax];
bool vis[nax];
void dfs(int nod, int pa){
    ++ cnt;
    vis[nod]  = true;
    for(int i : b[nod]){
        if(i != pa && !vis[i])
            dfs(i, nod);
    }
}


int main(){
    scanf("%d",  &n);
    for(int i = 1 ;i <= n; i ++){
        a[i].read();
    }
    sort(a + 1 ,  a + 1 + n);
    int tot = 0;
    set<pair<int , int >> s;
    set<pair<int , int >> :: iterator it;
    for(int i = 1 ;i <= n; i ++){
        while(!s.empty() && s.begin() -> first < a[i].l)
        s.erase(s.begin());
        it = s.lower_bound(make_pair(a[i].r, -1));
        while(it != s.begin()){
            it = prev(it);
            ++ tot;
            if(tot >= n)return !printf("NO");
            b[it -> second].push_back(i);
            b[i].push_back(it -> second);
        }
        s.emplace(a[i].r, i);
    }
   // printf("TOT =  %d\n", tot);
    if(tot != n - 1) return !printf("NO");
    dfs(1 , 0);
    printf(cnt == n ? "YES" : "NO");
}