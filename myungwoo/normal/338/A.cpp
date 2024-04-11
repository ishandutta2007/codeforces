#include <iostream>
using namespace std;

#define MOD 1000000009
typedef long long lld;

int N,M,K;
lld ans;

int main()
{
        int i;
        lld s,e,m,t=0,v,sum;
        cin >> N >> M >> K;
        s = 0, e = M;
        while (s <= e){
                m = (s+e)>>1;
                sum = K*m;
                lld space = N-K*m;
                sum += (space/K)*(K-1)+space%K;
                if (sum >= M) e = m-1, t = m;
                else s = m+1;
        }
        t++;
        v = 2; ans = 1;
        for (i=0;i<60;i++,v=v*v%MOD) if ((t>>i)&1) ans = (ans*v)%MOD;
        ans = (ans-2+MOD)%MOD*K%MOD;
        ans = (ans+M-K*(t-1))%MOD;
        cout << ans << endl;
}