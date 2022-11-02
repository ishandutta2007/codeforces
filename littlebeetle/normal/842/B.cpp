#include<cstdio>
#include<cmath>
using namespace std;
int R,r,d;
int n,x,y,z,ans;
int main(){
	scanf("%d%d%d",&x,&y,&n);
	R=x;
	r=x-y;
	while(n--){
		scanf("%d%d%d",&x,&y,&z);
		d=x*x+y*y;
		if((r+z)*(r+z)<=d&&d<=(R-z)*(R-z))
			ans++;
	}
	printf("%d",ans);
}