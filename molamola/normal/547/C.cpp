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

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n, q;
int A[500050], fp[500050];
int pr[500050];
int d[500050];
int ml[100], pv[100];
ll ans;
vector <int> dv[500050];

int main(){
    pr[0] = pr[1] = 1;
    for(int i=2;i<=500000;i++){
        if(!pr[i]){
            for(int j=i;j<=500000;j+=i)dv[j].pb(i), pr[j] = 1;
        }
    }
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",A+i);
    for(int i=0;i<q;i++){
        int y, x; scanf("%d", &y); x = A[y-1];
        int z = sz(dv[x]);
        ml[0] = 1, pv[0] = 1;
        if(fp[y])ans -= --d[1];
        else ans += d[1]++;
        for(int j=1;j<1<<z;j++){
            for(int k=0;k<z;k++){
                if(1<<k & j){
                    ml[j] = ml[j ^ 1<<k] * dv[x][k];
                    pv[j] = 1-pv[j ^ 1<<k];
                    break;
                }
            }
            if(fp[y])d[ml[j]]--;
            ans += (fp[y] ^ pv[j] ? d[ml[j]] : -d[ml[j]]);
            if(!fp[y])d[ml[j]]++;
        }
        fp[y] = 1-fp[y];
        printf("%lld\n", ans);
        //for(int j=0;j<=30;j++)printf("%d ", d[j]);puts("");
    }
    return 0;
}