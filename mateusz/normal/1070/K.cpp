#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - )
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size()
#define VI vector<int>
#define PII pair<int,int>

const int N = 100005;

int n, k, a[N];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    scanf("%d %d", &n, &k);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
       scanf("%d", &a[i]);
       sum += a[i];
    }
    
    if (sum % k != 0) {
        printf("No\n");
        return 0;
    }

    sum /= k;
    vector<int> ans;
    int s = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        cnt++;
        if (s == sum) {
            ans.push_back(cnt);
            s = 0;
            cnt = 0;
        } else if (s > sum) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    for (int x : ans) printf("%d ", x);
    printf("\n");
    
  return 0;
}