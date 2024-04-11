#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

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

lld L,R; int K;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> L >> R >> K;
    if (R-L+1 < 10){
        int S = R-L+1;
        lld ans = 1e18;
        vector <lld> list;
        for (int msk=1;msk<(1<<S);msk++){
            lld x = 0; int cnt=0;
            vector <lld> tmp;
            for (i=0;i<S;i++) if (msk&(1<<i)){
                x ^= L+i; cnt++;
                tmp.pb(L+i);
            }
            if (cnt > K) continue;
            if (ans > x) ans = x, list = tmp;
        }
        cout << ans << "\n" << sz(list) << "\n";
        for (lld x: list) cout << x << " ";
        cout << "\n";
        return 0;
    }
    if (K == 1){
        cout << L << "\n" << 1 << "\n" << L << "\n";
        return 0;
    }
    lld a = L&1?L+1:L;
    if (K == 2){
        cout << "1\n2\n" << a << " " << a+1 << endl;
        return 0;
    }
    if (K >= 4){
        cout << "0\n4\n" << a << " " << a+1 << " " << a+2 << " " << a+3 << "\n";
        return 0;
    }
    lld p = 1, q = 3;
    while (q <= R){
        if (p >= L){
            cout << "0\n3\n" << p << " " << q-1 << " " << q << "\n";
            return 0;
        }
        p = (p<<1)+1;
        q <<= 1;
    }
    cout << "1\n2\n" << a << " " << a+1 << endl;
}