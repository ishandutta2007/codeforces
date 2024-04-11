#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		if(n&1){
			if(n==1)putchar('a');
			else{
				for(ri i=n>>1;i;--i)putchar('a');
				putchar('b'),putchar('c');
				for(ri i=n-(n>>1)-2;i;--i)putchar('a');
			}
		}
		else{
			for(ri i=n>>1;i;--i)putchar('a');
			putchar('b');
			for(ri i=(n>>1)-1;i;--i)putchar('a');
		}
		putchar(10);
	}
	return 0;
}