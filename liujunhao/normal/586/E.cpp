#include<cstdio>
#include<algorithm>
using namespace std;
long long x,y,cnt;
pair<long long,char>a[1000];
long long gcd(long long x,long long y){
	long long t;
	while(y){
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}
void solve(long long x,long long y){
	while(y){
		if(x>y){
			a[++cnt]=make_pair(x/y,'A');
			x%=y;
			if(!x&&y==1){
				a[cnt].first--;
				return;
			}
		}
		else{
			a[++cnt]=make_pair(y/x,'B');
			y%=x;
			if(!y&&x==1){
				a[cnt].first--;
				return;
			}
		}
	}
	
}
int main()
{
	scanf("%I64d%I64d",&x,&y);
	if(gcd(x,y)>1){
		puts("Impossible");
		return 0;
	}
	solve(x,y);
	for(int i=1;i<=cnt;i++)
		printf("%I64d%c",a[i].first,a[i].second);
}