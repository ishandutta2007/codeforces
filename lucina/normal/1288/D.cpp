#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax][8];
int n , m, id[260];
pair<int, int> ans;
bool ok(int x){
    memset(id, -1, sizeof(id));
    for(int i = 1 ; i <=  n; i++){
        int cur = 0;
        for(int j = 0 ;j < m ;j ++){
            if(a[i][j] >= x)
                cur ^= (1 << j);
        }
        id[cur] = i;
    }
    for(int i = (1 << m) - 1 ; i >= 0 ; i --){
        for(int j = 0 ;j < m ;j ++){
            if(id[i | (1 << j)] != -1)
                id[i] = id[i | (1 << j)];
        }
    }
    for(int i = 0 ; i < (1 << m ) ; i++){
        if(id[i] != -1 && id[((1 << m) -1) ^ i] != -1){
            ans.first = id[i];
            ans.second = id[((1 << m) - 1) ^ i];
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1 ;i <= n ;i ++){
        for(int j = 0 ;j < m; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    int l = 0, r = 1e9 , mid;
    while(l <= r){
        mid = l + r >> 1;
        if(ok(mid)){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d %d\n", ans.first, ans.second);
}