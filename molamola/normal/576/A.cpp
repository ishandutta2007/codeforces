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

int pr[1010];
int n;
vector <int> ans;

int main() {
    for(int i=2;i<=1000;i++)pr[i] = 1;
    for(int i=2;i<=1000;i++){
        if(pr[i]){
            for(int j=i*i;j<=1000;j+=i)pr[j] = 0;
        }
    }
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(pr[i]){
            int t = i;
            while(t <= n)ans.pb(t), t *= i;
        }
    }
    printf("%d\n", sz(ans));
    for(int i=0;i<sz(ans);i++)printf("%d ", ans[i]);
    return 0;
}