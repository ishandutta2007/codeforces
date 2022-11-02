#include <bits/stdc++.h>
#define N 400005
#define LL long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int inf = 1000000000;
const int mod = 998244353;
int n;
int a[N];
LL sum[N];
LL sum0[N], all, ans, sum1[N];
LL detC, detP;
int en, fi;
bool ck(int L, int mid) {
    LL sumC = 0;
    sumC = sum[L];
    if(L + 2 * mid == n) return 0;
    sumC += sum0[L + 2 * mid] - sum0[L];
    //cout << "a" << mid << ' ' << sumC << ' ' << all - sumC + detP << endl;
    if(sumC + detC < all - sumC + detP) return 1;
    return 0;
}
void solve1() {
    for (int i = 1; i <= n; i += 1) {
        //int l = i + 2, r = n, ret = 0;
        int l = 1, r = (n - i) / 2, ret = 0;
        //cout << i << ' ' << l << ' ' << r << endl;
        while(r - l >= 0) {
            int mid = (l + r) >> 1;
            if(ck(i, mid)) {
                l = mid + 1, ret = mid;
            } else {
                r = mid - 1;
            }
        }
        //cerr << i <<' ' << ret << endl;
        //if(ret) ans += ret;
    }
}
void solve2() {
    for (int i = 0; i <= n; i += 1) {
        LL sumC = sum[i];
        if(sumC + detC < all - sumC + detP) ans ++;
    }
}
void work(int i, int L, int R, LL tmp) {
    if(tmp <= 0) return ;
    if((R - L) & 1) R --;
    while(R - L > 0) {
        int M = (R - L) / 2 + 1;
        int mid = L + M;
        if(M & 1) mid --;

        if(tmp <= 2 * (sum0[mid] - sum0[i])) R = mid - 2;
        else L = mid;
    }
    ans += (L - i) / 2;
    ans ++;
}
void do1() {
    for(int i = 2; i <= n; i += 1) {
        int L = i, R = n;
        LL tmp = all - 2 * sum[i];
        work(i, L, R, tmp + 2 * fi);
    }
    for(int i = 1; i <= n; i += 1){
        int L = i, R = n;
        LL tmp = all - 2 * sum[i];
        work(i, L, R, tmp);
    }
}
void do2() {
    for(int i = 2; i <= n - 3; i += 1){
        int L = i, R = n - 3;
        LL tmp = all - 2 * en - 2 * sum[i];
        work(i, L, R, tmp + 2 * fi);
    }
    for(int i = 1; i <= n - 3; i += 1){
        int L = i, R = n - 3;
        LL tmp = sum[n - 1] - 2 * sum[i] - en;
        work(i, L, R, tmp);
    }
}
int main() {
    //freopen("line1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    //T = 5;
    while(T--) {
        ans = 0;
        cin >> n;
       // n = rand() + 1;
        
        all = 0;
        for (int i = 1; i <= n; i += 1) //a[i] = 1000000000, all += a[i];
            cin >> a[i], all += a[i];
if(n == 1) {
            cout << 1 << '\n';
            continue ;
        }
        en = a[n]; fi = a[1];
        for (int i = 1; i <= n; i += 1) {
            sum[i] = sum[i - 1] + a[i];
            if(i >= 2)
            sum0[i] = sum0[i - 2] + a[i];
            else sum0[i] = a[i];
        }
solve1();
        do2();
        do1();

        //P
        for (int i = 2; i <= n; i += 1) {
            if(2 * sum[i] > all) ans ++;
        }

        ans %= mod;
        cout << ans << '\n';
    }

}