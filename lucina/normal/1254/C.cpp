#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int askCross(int x, int y , int z){
    printf("%d %d %d %d\n", 2, x, y, z);
    fflush(stdout);
    int p;
    scanf("%d", &p);
    return p;
}
ll askArea(int x,int y,int z){
    printf("%d %d %d %d\n", 1, x, y, z);
    fflush(stdout);
    ll p ;
    scanf("%lld", &p);
    return p;
}
void ans(vector<int> &p){
    assert(p[0] == 1);
    printf("0 ");
    for(int i : p)
        printf("%d ",i);
    printf("\n");
    fflush(stdout);
    exit(0);
}
int n;
vector<int> m[2], v[2];

int main(){
    scanf("%d", &n);
    for(int i = 3 ;i <= n; i ++){
        int ret = askCross(1, 2, i);
        if(ret < 0){
            m[0].push_back(i);
        }
        else m[1].push_back(i);
    }
    for(int t = 0 ; t < 2 ; ++ t){
    if(m[t].empty()) continue;
    vector<ll> area;
    for(int i : m[t]){
        area.push_back(askArea(1, 2, i));
    }
    ll Max = 0;
    int pt = -1;
    for(int i = 0 ;i < (int)m[t].size() ;i ++){
        if(area[i] > Max){
            Max = area[i];
            pt = m[t][i];
        }
    }
    vector<pair<ll, int>> lft, rgh;
    for(int i = 0 ;i < (int)m[t].size() ; i ++){
        if(m[t][i] == pt) continue;
        int res = askCross(m[t][i], pt, 1);
        if(res > 0) rgh.push_back(make_pair(area[i], m[t][i]));
        else lft.push_back(make_pair(area[i], m[t][i]));
    }
    sort(rgh.rbegin(), rgh.rend());
    sort(lft.begin(), lft.end());
    for(auto it: lft) v[t].push_back(it.second);
    v[t].push_back(pt);
    for(auto it:rgh) v[t].push_back(it.second);
    }
    vector<int> toprint;
    toprint.push_back(1);
    for(auto it = v[0].rbegin(); it != v[0].rend() ; ++ it)
        toprint.push_back(*it);
    toprint.push_back(2);
    for(auto it = v[1].rbegin(); it != v[1].rend(); ++ it)
        toprint.push_back(*it);
    ans(toprint);
}