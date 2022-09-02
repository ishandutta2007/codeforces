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

int n, k;
vector <int> v[100010];
int len[100010];
int w[100010];
int chk[100010];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d",len+i);
        for(int j=0;j<len[i];j++){
            int x; scanf("%d",&x);
            v[i].pb(x);
            w[x] = i;
        }
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        if(w[i] != w[i+1]){
            if(!chk[w[i]])ans += len[w[i]]-1, chk[w[i]] = 1;
            if(!chk[w[i+1]])ans += len[w[i+1]]-1, chk[w[i+1]] = 1;
            ans++;
        }
        else if(chk[w[i]])ans++;
        len[w[i]]--;
    }
    printf("%d",ans);
    return 0;
}