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

typedef pair<ll, ll> Pl;
typedef pair<Pl, ll> Pll;
Pll p[200020];
Pl A[200020];
ll inp[200020][2];
int ans[200020];
int n, m;

priority_queue<Pl> pq;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld%lld", inp[i], inp[i]+1);
        if(i > 0){
            p[i-1] = Pll(Pl(inp[i][0] - inp[i-1][1], inp[i][1] - inp[i-1][0]), i);
        }
    }
    --n;
    for(int i=0;i<m;i++){
        scanf("%lld", &A[i].Fi);
        A[i].Se = i+1;
    }
    sort(p, p+n);
    sort(A, A+m);
    int r = 0;
    for(int i=0, j=0;i<m;i++){
        while(j < n && p[j].Fi.Fi <= A[i].Fi){
            pq.push(Pl(-p[j].Fi.Se, p[j].Se));
            j++;
        }
        if(pq.empty()){
            continue;
        }
        Pl t = pq.top();
        pq.pop();
        if(-t.Fi < A[i].Fi){
            printf("No");
            return 0;
        }
        ans[t.Se] = (int)A[i].Se;
        r++;
    }
    if(r != n){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)printf("%d ", ans[i]);
    return 0;
}