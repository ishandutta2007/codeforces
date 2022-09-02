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
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n;
int p[100010];
int chk[100010];

void solve(int x){
    printf("YES\n");
    printf("%d %d\n", x, p[x]);
    for(int i=1;i<=n;i++)chk[i] = 0;
    chk[x] = chk[p[x]] = 1;
    for(int i=1;i<=n;i++){
        if(chk[i] == 0){
            int t = i, c = 0;
            do{
                if(c % 2 == 0)printf("%d %d\n", t, x);
                else printf("%d %d\n", t, p[x]);
                chk[t] = 1, t = p[t], c++;
            }while(t!=i);
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++){
        if(p[i] == i){
            printf("YES\n");
            for(int j=1;j<=n;j++){
                if(i != j)printf("%d %d\n", j, i);
            }
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i])continue;
        int t = i, c = 0;
        do{chk[t] = 1, t = p[t], c++;}while(t!=i);
        if(c % 2 == 1){
            printf("NO");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(p[p[i]] == i){
            solve(i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}