#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e3+10;
int T,n,gcd;
struct node{
	int x,y;
}a[N];
std::set<int> set[2];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i].x),read(a[i].y);
	while(true){
		set[0].clear(),set[1].clear();
		for(int i=1;i<=n;i++)set[(a[i].x+a[i].y)&1].insert(i);
		if(set[0].size()==0||set[0].size()==n){
			for(int i=1;i<=n;i++){
				int x=a[i].x,y=a[i].y;
				a[i].x=(x+y)>>1,a[i].y=(x-y)>>1;
			}
		}else{
			printf("%lu\n",set[0].size());
			for(int x:set[0])printf("%d ",x);
			break;
		}
	}
}