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

typedef long long lld;

lld N, K, L, M;
lld P, Q;

struct MAT{
    lld m[3][3];

    MAT operator * (const MAT &ot)const{
        MAT ret = {0,};
        for (int i=0;i<3;i++) for (int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                ret.m[i][j] = (ret.m[i][j] + (m[i][k] * ot.m[k][j])) % M;
            }
        }
        return ret;
    }
};

void calc()
{
    lld p = N;
    MAT r = {0,}, v = {0,};
    for (int i=0;i<3;i++) r.m[i][i] = 1;
    v.m[0][0] = v.m[0][1] = v.m[1][0] = v.m[2][1] = 1;
    v.m[2][2] = 2;
    for (;p;p>>=1,v=v*v) if (p&1) r = r * v;
    P = r.m[0][0] + r.m[1][0]; Q = r.m[2][0];
}

int main()
{
    cin >> N >> K >> L >> M;
    calc();
    if (L < 63 && K >= (1LL << L)){ puts("0"); return 0; }
    lld ans = 1;
    for (int i=0;i<L;i++){
        if (K&1) ans = ans * Q % M;
        else ans = ans * P % M;
        K >>= 1;
    }
    cout << ans % M << endl;
}