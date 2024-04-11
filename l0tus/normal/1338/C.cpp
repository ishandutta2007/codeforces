#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;

bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    //int N;
    //cin >> N;
    int T;
    ll X[4] = {0,2,3,1};
    cin >> T;
    while(T--){
    	ll N;
    	cin >> N;
    	int Y = Y = (N-1)%3;
    	N = (N+2)/3;
    	ll K=N, cnt = 1;
    	while(K>cnt){
    		K -= cnt;
    		cnt = cnt<<2;
    	}
    	ll A = cnt+K-1;
    	ll B = cnt*2;
    	K--;
    	cnt = 1;
    	while(K){
    		B += X[K%4]*cnt;
    		K/=4;
    		cnt*=4;
    	}
    	ll ans;
    	if(Y==0) ans = A;
    	if(Y==1) ans = B;
    	if(Y==2) ans = A^B;
    	cout << ans << '\n';
    }
}