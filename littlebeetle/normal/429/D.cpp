#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200002;
#define ll long long
struct p{
	ll x,y;
}a[N],b[N];
ll n,m,i,j,A[N];
ll s=1ll<<60;
bool cmp(p u,p v){
	return u.x<v.x;
}
bool Cmp(p u,p v){
	return u.y<v.y;
}
void f(int l,int r){
	int mid=l+r>>1;
	if(l+1<r){
		mid=l+r>>1;
		f(l,mid);
		f(mid+1,r);
	}
	m=0;
	for(i=l;i<=r;i++)
		if(a[i].x>=a[mid].x-s&&a[i].x<=a[mid].x+s)
			m++,b[m].x=a[i].x,b[m].y=a[i].y;
	sort(b+1,b+m+1,Cmp);
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m&&j-i<7;j++)
			s=min(s,(b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y));
}
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",A+i),a[i]=(p){i,A[i]+=A[i-1]};
	sort(a+1,a+n+1,cmp);
	f(1,n);
	printf("%lld",s);
		//while(1);
}