#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=505;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n;
ll a[N][N],aim;

bool check(){
	rep(i,1,n) rep(j,1,n) if(a[i][j]<=0) return 0;
	rep(i,1,n){
		ll tmp=0;
		rep(j,1,n) tmp+=a[i][j];
		if(tmp!=aim) return 0;
		tmp=0;
		rep(j,1,n) tmp+=a[j][i];
		if(tmp!=aim) return 0;
	}
	ll tmp=0;
	rep(i,1,n) tmp+=a[i][i];
	if(tmp!=aim) return 0;
	tmp=0;
	rep(i,1,n) tmp+=a[i][n-i+1];
	if(tmp!=aim) return 0;
	return 1;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) rep(j,1,n) scanf("%I64d",a[i]+j);
	if(n==1) {puts("1");return 0;}
	ll sum=0;
	rep(i,1,n){
		ll tmp=0;
		rep(j,1,n){
			if(a[i][j]==0){tmp=-1;break;}
			tmp+=a[i][j];
		}
		if(tmp!=-1){sum=tmp;break;}
	}
	aim=sum;
	int x,y;
	rep(i,1,n) rep(j,1,n) if(!a[i][j]) x=i,y=j;
	rep(i,1,n) if(a[i][y]) sum-=a[i][y];
	a[x][y]=sum;
	if(!check()){
		puts("-1");
		return 0;
	}
	printf("%I64d\n",a[x][y]);
}