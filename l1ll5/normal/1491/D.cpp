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
int q;
void doit(int x, int y) {
	
	if(x > y) {
    		puts("NO");
    		return ;
		}
		if(x == y) {
			puts("YES");
    		return ;
		}
    	while(x < y) {
    		int ok = 0;
    		for (int i = 30; i >= 0; i -= 1) {
    			if( ( (x >> i) & 1) && ( x + (1<<i) <= y ) ) {
    				x += (1<<i);
					ok = 1; 
    				break ;
				}
			}
    		if(ok==0) break ;
    	
		}
		if(x == y) 
		puts("YES"); else puts("NO");
		
    	return ;
}
int main() {
	//freopen("0.in","r",stdin); 
	scanf("%d", &q); 
    while(q --) {
    	int x, y;
		scanf("%d %d", &x, &y); 
		doit(x, y);
    	
    	
	}
}