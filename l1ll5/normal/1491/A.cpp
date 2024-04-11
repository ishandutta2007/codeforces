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
int n, q;
int a[N];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read(), q = read();
    int one = 0;
    for (int i = 1; i <= n ; i += 1) {
		a[i] = read();
		if(a[i]) one ++;
	} 
	while(q--) {
		int o =read();
		if(o== 1) {
			int x = read();
			if(a[x]) one--;
			else one++;
			a[x] = a[x] ^ 1;
		}
		else {
			int k = read();
			if(one >= k) {
				printf("1\n"); 
			}  else 	printf("0\n"); 
		}
	}
}