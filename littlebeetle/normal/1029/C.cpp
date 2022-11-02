#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300002;
struct p{
	int x,d;
	bool operator<(const p &k)const{
		return k.x<x;
	}
}l[N];
struct q{
	int x,d;
	bool operator<(const q &k)const{
		return k.x>x;
	}
}r[N];
int n,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&l[i].x,&r[i].x),l[i].d=r[i].d=i;
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	printf("%d",max(0,r[1].d==l[1].d?r[2].x-l[2].x:max(r[2].x-l[1].x,r[1].x-l[2].x)));
	return 0;
}