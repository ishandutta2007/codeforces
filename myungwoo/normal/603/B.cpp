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

const int MOD = 1e9 + 7;
int P, K;

int pow(int n, int p)
{
    int v = n, ret = 1;
    for (;p;p>>=1,v=(lld)v*v%MOD) if (p&1)
        ret = (lld)ret * v % MOD;
    return ret;
}

int main()
{
    cin >> P >> K;
    if (K == 1){
        printf("%d\n", pow(P, P));
    }else if (K == 0){
        printf("%d\n", pow(P, P-1));
    }else{
        int m = 0, v = 1;
        for (;;){
            v = (lld)v * K % P;
            m++;
            if (v == 1) break;
        }
        printf("%d\n", pow(P, (P-1)/m));
    }
}