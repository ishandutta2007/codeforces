#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case,x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&x,&y);
		while(y>0){
			ri cnt=(x+y)/(y+1);
			while(cnt>0&&x>0)putchar('R'),--cnt,--x;
			putchar('B'),--y;
		}
		while(x>0)putchar('R'),--x;
		putchar(10);
	}
	return 0;
}