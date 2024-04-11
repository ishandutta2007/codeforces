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

set <int> S;
map <int,int> M;
const ll MOD = 1e9 + 7;
int n;
int ans[200020];
Pi p[200020];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i].Fi);
    for(int i=1;i<=n;i++)p[i].Se = i;
    sort(p+1, p+1+n);
    int now = n+1;
    S.insert(0); S.insert(n+1); M[n+1] = 1;
    vector <int> v;
    for(int i=1;i<=n;i++){
        v.pb(p[i].Se);
        if(i == n || p[i+1].Fi != p[i].Fi){
            for(auto i : v){
                S.insert(i);
                auto it = S.find(i);
                auto jt = it++;
                auto kt = jt--;
                M[*it - *jt]--;
                if(M[*it - *jt] == 0)M.erase(*it - *jt);
                M[*it - *kt]++;
                M[*kt - *jt]++;
            }
            auto mt = M.end();
            --mt;
            int mx = mt -> Fi;
            for(int j=now-1;j>=mx;j--)ans[j] = p[i].Fi;
            if(now > mx)now = mx;
            v.clear();
        }
    }
    for(int i=1;i<=n;i++)printf("%d ", ans[i]);
    return 0;
}