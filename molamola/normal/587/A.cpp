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

int p[1001100];

void solve(int tc) {
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x); p[x]++;
    }
    int ans = 0;
    for(int i=0;i<=1001000;i++){
        p[i+1] += p[i] / 2;
        p[i] %= 2;
        if(p[i] == 1)++ans;
    }
    printf("%d",ans);
}

int main(){
    int Tc = 1;// scanf("%d",&Tc);
    for(int i=1;i<=Tc;i++){
        solve(i);
    }
    return 0;
}