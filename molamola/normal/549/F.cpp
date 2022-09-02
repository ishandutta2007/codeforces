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

int n, k;
int a[300030];
ll s[300030], ans;
int tmpL[1000010], tmpR[1000010];

void solve(int L, int R){
    if(R == L)return;
    int M = (L+R)/2;
    solve(L, M);
    solve(M+1, R);
    int Lv = M+1, Rv = M;
    while(Lv != L || Rv != R){
        if((Rv == R ? 2e9 : a[Rv+1]) <= (Lv == L ? 2e9 : a[Lv-1])){
            int t = Rv + 1;
            while(t != R+1 && a[t] <= a[Rv+1])t++;
            //Do(Lv, M, Rv+1, t-1, a[Rv+1]);
            for(int i=Rv+1;i<=t-1;i++)ans += tmpL[(s[i]+k-a[Rv+1]%k)%k], tmpR[s[i]]++;
            Rv = t-1;
        }
        else{
            int t = Lv - 1;
            while(t != L-1 && a[t] <= a[Lv-1])t--;
            //Do(t+1, Lv-1, M+1, Rv, a[Lv-1]);
            for(int i=t+1;i<=Lv-1;i++)ans += tmpR[(s[i-1]+a[Lv-1])%k], tmpL[s[i-1]]++;
            Lv = t+1;
        }
    }
    for(int i=L;i<=M;i++)tmpL[s[i-1]]--;
    for(int i=M+1;i<=R;i++)tmpR[s[i]]--;
}

int main(){
    scanf("%d%d",&n,&k);
    a[0] = a[n+1] = 2e9;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)s[i] = (s[i-1] + a[i]) % k;
    //Do(1, 2, 3, 4, 0);
    solve(1, n);
    printf("%lld",ans);
    return 0;
}