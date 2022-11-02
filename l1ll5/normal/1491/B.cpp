#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 200005
#define INF 0x3f3f3f3f
int n, u, v;
int a[N];
int t;
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while( t -- ) {
    	cin >> n >> u >> v;
    	int ok = 1;
    	int lk = 0;
    	for(int i= 1 ; i <=n ; i += 1) cin >> a[i];
    	for(int i= 1 ; i <=n ; i += 1) {
			if(i != n && a[i] != a[i+1]) {
				ok = 0;
			}
			if(i != n && abs(a[i] - a[i+1]) > 1) {
				lk = 1;
			}
		} 
		if(lk) {
			cout << 0 << '\n';
			continue ;
		}
		if(ok) {
			cout << min(2 * v, u + v) << '\n';
			continue ;
		}
		cout << min(u, v) << '\n';
		
	}
}