#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

char ch[3][110];
int pos[3][110];
int n, k;

bool chk(int x,int y){
    return y < n && 'A' <= ch[x][y] && ch[x][y] <= 'Z';
}

bool dfs(int x,int y){
    if(y >= n-1)return true;
    if(pos[x][y] != -1)return pos[x][y];
    if(ch[x][y+1] != '.')return pos[x][y] = 0;
    for(int j=0;j<3;j++){
        if(abs(x-j) > 1)continue;
        if(!chk(j, y+1) && !chk(j, y+2) && !chk(j, y+3) && dfs(j, y+3))return pos[x][y] = 1;
    }
    return pos[x][y] = 0;
}

void solve(int tc) {
    memset(pos, -1, sizeof pos);
    scanf("%d%d",&n,&k);
    for(int i=0;i<3;i++)scanf("%s",ch[i]);
    int start = (ch[0][0] == 's' ? 0 : (ch[1][0] == 's' ? 1 : 2));
    
    printf("%s\n", dfs(start, 0) ? "YES" : "NO");
}

int main(){
    int Tc; scanf("%d",&Tc);
    for(int i=1;i<=Tc;i++){
        solve(i);
    }
    return 0;
}