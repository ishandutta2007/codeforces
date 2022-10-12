#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int ran = 222222;

int n, T;
int t[ran];

bool got[ran];

vector<pair<int, int> > v;

int main() {
    scanf("%d%d", &n, &T);
    T--;
    for(int i=1;i<=n;i++) scanf("%d", &t[i]);
    
    memset(got, false, sizeof got);
    v.clear();
    int st = min(T, n), cur = 0, ans = 0;
    for(int i=st;i>0;i--) {
        if (t[i] <= i + (T-st)) {
            cur++;
            got[i] = true;
        }
        else v.push_back(make_pair(t[i]-(i + T-st), i));
    }
    //for(int i=0;i<(int)v.size();i++) printf("%d %d\n", v[i].first, v[i].second);
    ans = cur;
    sort(v.begin(), v.end());
    
    int it = 0, det = 0;
    for(int i=st-1;i>0;i--) {
        cur -= got[i+1];
        det ++;
        while(it < (int)v.size() && v[it].first <= det) {
            int p = v[it].second;
            it++;
            if (p <= i) {
                cur++;
                got[p] = true;
            }
        }
        ans = max(ans, cur);
    }
    
    printf("%d\n", ans);
    
    return 0;
}