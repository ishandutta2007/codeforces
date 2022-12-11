#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e6+5;

ll H[MN],sum;

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);
 
    ll N;
    cin >> N;
    for(ll i=0; i<N; i++){
    	cin >> H[i];
    	sum += H[i];
    }
    ll s = 0, e = 1e12;
    while(s<e){
    	ll m = (s+e+1)/2;
    	if(m*N+N*(N-1)/2<=sum) s = m;
    	else e = m-1;
    }
    ll d = sum-s*N-N*(N-1)/2;
    for(ll i=0; i<N; i++){
    	if(i<d) cout << s+i+1 << ' ';
    	else cout << s+i << ' ';
    }
}