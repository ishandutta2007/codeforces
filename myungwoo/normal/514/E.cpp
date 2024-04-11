#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

const int MOD = 1e9+7;
int N, X;
int cnt[101];
int D[201]={1};

struct MAT{
    int m[101][101];
    
    MAT operator * (const MAT &ot)const{
        MAT ret={0};
        for (int i=0;i<101;i++) for (int j=0;j<101;j++){
            for (int k=0;k<101;k++){
                ret.m[i][j] = (ret.m[i][j] + (lld)m[i][k]*ot.m[k][j])%MOD;
            }
        }
        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> X;
    for (int i=1;i<=N;i++){
        int d;
        cin >> d;
        cnt[d]++;
    }
    for (int i=1;i<201&&i<=X;i++){
        for (int j=1;j<=i&&j<101;j++){
            D[i] = (D[i]+(lld)D[i-j]*cnt[j])%MOD;
        }
    }
    int sum = 0;
    for (int i=0;i<100;i++) sum = (sum+D[i])%MOD;
    if (X < 100){ cout << sum << endl; return 0; }
    X -= 99;
    MAT v = {0, }, t = {0, };
    for (int i=0;i<99;i++) v.m[i][i+1] = 1;
    for (int i=0;i<100;i++){
        v.m[99][i] = cnt[100-i];
        v.m[100][i] = cnt[100-i];
    }
    v.m[100][100] = 1;
    for (int i=0;i<101;i++) t.m[i][i] = 1;
    for (;X;X>>=1){
        if (X&1) t = t*v;
        v = v*v;
    }
    int ans = 0;
    for (int i=0;i<100;i++) ans = (ans + (lld)t.m[100][i]*D[i])%MOD;
    ans = (ans + (lld)t.m[100][100]*sum)%MOD;
    cout << ans << endl;
}