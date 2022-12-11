#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int N,M,K;
long long cnt;

ll pw(int a, int b)
{
    ll res = 1, val = a;
    while(b){
        if(b%2) res = res*val%MOD;
        val = val*val%MOD;
        b/=2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    //cnt = 1;
    cout << pw(pw(2,K)-1,N);
    //while(K--){
    //   cnt = cnt*2%MOD;
    //}
    //cnt--;
}