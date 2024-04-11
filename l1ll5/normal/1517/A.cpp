#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
long long bin[20];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while(T--) {
        long long n;
        cin >> n;
        if(n % 2050 != 0) {
            cout << -1 << endl;
        } else {
            n = n / 2050;
            long long ans = 0;
            while(n) {
                ans += n % 10;
                n /= 10;
            }
            cout << ans << endl;
        }
    }
}