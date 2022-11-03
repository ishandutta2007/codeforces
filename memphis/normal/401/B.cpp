#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define maxn 4005

int x,N,maxans,minans,now;

struct Query{
	int num1,num2;
}a[maxn];

inline bool cmp(const Query &a,const Query &b){return a.num2<b.num2;}

int main(){
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);

	scanf("%d%d",&now,&N);
	rep(i,1,N){
		scanf("%d",&x);
		if(x==1)scanf("%d%d",&a[i].num2,&a[i].num1);
		else scanf("%d",&a[i].num2);
	}
	sort(a+1,a+1+N,cmp);
	a[++N].num2=now;
	rep(i,1,N){
		if(!a[i].num1)a[i].num1=a[i].num2;
		maxans+=a[i].num2-a[i-1].num1-1;
		minans+=a[i].num2-a[i-1].num1>>1;
	}
	printf("%d %d\n",minans,maxans);
}