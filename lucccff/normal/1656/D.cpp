#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

const int MAXN=100000;
int prime[MAXN+1];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    getPrime();
    while (t--) {
        long long n, x;
        cin >> n;
        x = 2;
        while(n % x == 0) {
            x <<= 1;
        }
        if (n * 2 / x >= x + 1) {
            cout << x << endl;
        }
        else if (x != n * 2) {
            cout << n * 2 / x << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}