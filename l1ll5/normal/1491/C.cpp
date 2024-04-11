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
int n;
int s[N];
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
} 
int t;
int main() {
	//freopen("0.in","r",stdin); 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    //t = 1;
    while( t -- ) {
    	cin >> n;
    	// n = 5000;
    	long long ans = 0;
		for (int i = 1; i <= n ; i += 1) {
			cin >> s[i];
		//	s[i] = 1e9; 
			fa[i] = i;
		}
	//	cerr <<"a" << endl;
		for(int i = 1; i <= 10000; i+= 1) fa[i]=i;
		
		for(int i = 1; i <= 5000; i+= 1) {
			if(s[i] == 1) {
				fa[i] = find(i + 1);
			}
		}
		
		for (int i = 1; i <= n ; i += 1) {
			if(s[i] == 1) continue ;
			if(s[i] > 5000) {
				ans += (s[i] - 5000);
				s[i] = 5000;
			}
			while(s[i] != 1) {
				/*for(int j = 1; j <= n ; j += 1) {
					cout <<s[j]<< ' ';
				}
				cout << endl;*/
			//	cerr << i << ' '<< s[i] << endl; 
				ans ++;
				int pos = i;
				pos = find(pos);
				while(pos <= n) {
					s[pos] --;
				//	cerr << pos << endl;
					if(s[pos] == 1) {
						fa[pos] = find(pos + 1);
					}
					pos = pos + s[pos] + 1;
					if(pos <= n)
					pos = find(pos);
				}
			}
		}
		cout << ans << '\n';
	}
}