#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
typedef long long ll;
using namespace std;
const int MAXN=100;
int n,a[MAXN];
ll Query(int x,int y){
	ll res=0;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%lld",&res);
	assert(~res);
	return res;
	for(int i=x; i<=y; i++)
		for(int j=i+1; j<=y; j++)
			if(a[i]>a[j]) res++;
	return res;
}
int _x,_y,_z;
inline bool gex(int w){
	return w==n||Query(1,w+1);
	return w>=_x;
}
int x,y,z;
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		/*
		scanf("%d%d%d",&_x,&_y,&_z);
		for(int i=1; i<=n; i++)
			a[i]=i;
		reverse(a+_x,a+_y);
		reverse(a+_y,a+_z+1);
		*/
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(gex(mid)) r=mid;
			else l=mid+1;
		}
		x=l;
		y=x+Query(x,n)-Query(x+1,n)+1;
		z=y+Query(y,n)-Query(y+1,n);
		printf("! %d %d %d\n",x,y,z);
		fflush(stdout);
	}
	return 0;
}