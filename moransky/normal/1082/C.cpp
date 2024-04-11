#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100010;
int n, m, s[N], r[N], ans[N], maxn = -1;
vector<int> G[N], sum[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", s + i, r + i);
        G[s[i]].push_back(r[i]);
    }
    for(int i = 1; i <= m; i++) 
        sort(G[i].begin(), G[i].end(), greater<int>() );
    
    for(int i = 1; i <= m; i++){
        int sum = 0;
        maxn = max(maxn, (int)G[i].size());
        for(int j = 0; j < G[i].size(); j++){
            sum += G[i][j];
            if(sum > 0)ans[j + 1] += sum;
        }
    }
    int res = 0;
    for(int i = 1; i <= maxn; i++) res = max(res, ans[i]);
    printf("%d", res);
    return 0;
}