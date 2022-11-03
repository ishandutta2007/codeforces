#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 300005
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)

int N,l[maxn],r[maxn],a[maxn],p,Max,sum,last;

int main(){
	scanf("%d",&N);
	rep(i,1,N) scanf("%d",&a[i]);
	rep(i,1,N) l[i]=r[i]=i;
	rep(i,2,N){for(p=i;l[p]-1&&!(a[l[p]-1]%a[i]);p=l[p]-1);l[i]=l[p];}
	dep(i,N-1,1){for(p=i;r[p]+1!=N+1&&!(a[r[p]+1]%a[i]);p=r[p]+1);r[i]=r[p];}
	rep(i,1,N) if(r[i]-l[i]>Max)Max=r[i]-l[i];
	rep(i,1,N) if(r[i]-l[i]==Max && l[i]!=last)++sum,last=l[i];
	printf("%d %d\n",sum,Max);
	bool flag=false; last=0;
	rep(i,1,N) if(r[i]-l[i]==Max){
		if(l[i]==last)continue;
		if(flag)putchar(' ');else flag=1; 
		printf("%d",last=l[i]);
	}
}