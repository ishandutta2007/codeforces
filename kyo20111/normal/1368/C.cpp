#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<pair<int,int>> v;
int main(){
    scanf("%d",&n);

    int x = 1, y = 1;
    for(int i=0;i<=n;i++){
        v.push_back({x, y});
        v.push_back({x+1, y});
        v.push_back({x, y+1});
        x++, y++;
    }
    v.push_back({x, y});

    printf("%d\n",v.size());
    for(auto [x,y] : v) printf("%d %d\n",x,y);
}