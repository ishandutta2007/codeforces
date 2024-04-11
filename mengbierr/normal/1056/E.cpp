#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
typedef pair < int, int > P ;
const int Maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f ;
const double PI = acos(-1.0) ;
const ull seed = 133 ;
const int _Max = 1000 + 10 ;
const ll Mod = 1e9 + 7 ;
 
int lens, lent ;
char s[Maxn], t[Maxn] ;
int tot0, tot1 ;
ll pre[Maxn], Ppow[Maxn] ;
 
void solve (){
    pre[0] = 0 ;
    Ppow[0] = 1 ;
    for (int i = 1; i <= lent; i++){
        pre[i] = (pre[i - 1] * seed + (t[i] - 'a' + 1)) % Mod ;
        Ppow[i] = Ppow[i - 1] * seed % Mod ;
    }
}
 
inline ll Hash (int l, int r){
    return (pre[r] - pre[l - 1] * Ppow[r - (l - 1)] % Mod + Mod) % Mod ;
}
 
int main (){
    cin >> s + 1 >> t + 1 ;
    lens = strlen(s + 1) ;
    lent = strlen(t + 1) ;
    for (int i = 1; i <= lens; i++){
        tot0 += (s[i] == '0') ;
        tot1 += (s[i] == '1') ;
    }
    int ans = 0 ;
    int len0, len1 ;
    solve() ;
    for (len0 = 1; len0 < lent; len0++){
        if (tot0 * len0 >= lent) break ;
        if ((lent - tot0 * len0) % tot1 > 0) continue ;
        len1 = (lent - tot0 * len0) / tot1 ;
        bool flag = 1 ;
        int cnt0 = 0, cnt1 = 0 ;
        ll hashr0 = 0, hashr1 = 0 ;
        for (int i = 1; i <= lens; i++){
            if (s[i] =='0') {
                int l = cnt0 * len0 + cnt1 *len1 + 1, r = l + len0 - 1 ;
                ll _hash = Hash (l, r) ;
                if (hashr0 == 0) hashr0 = _hash ;
                else {
                    if (hashr0 != _hash) {
                        flag = 0 ;
                        break ;
                    }
                }
                cnt0++;
            }
            if (s[i] == '1'){
                int l = cnt0 * len0 + cnt1 *len1 + 1, r = l + len1 - 1 ;
                ll _hash = Hash (l, r) ;
                if (hashr1 == 0) hashr1 = _hash ;
                else {
                    if (hashr1 != _hash) {
                        flag = 0;
                        break ;
                    }
                }
                cnt1++ ;
            }
            if (hashr0 != 0 && hashr1 != 0 && hashr0 == hashr1) {
                flag = 0 ;
                break ;
            }
        }
        if (flag) ans++ ;
    }
    cout << ans << endl ;
    return 0;
}