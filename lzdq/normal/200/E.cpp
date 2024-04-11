#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int INF=0x3fffffff;
int n,a,b,c,s;
int ans=INF,ax,ay,az;
void Check(int x,int y,int z){
	if(x*a+y*b+c*z==s&&0<=x&&x<=y&&y<=z){
		int d=abs(x*a-y*b)+abs(y*b-c*z);
		if(d<ans){
			ans=d;
			ax=x;
			ay=y;
			az=z;
		}
	}
	return ;
}
int exgcd(int a,int b,int &x,int &y){
	if(!b) return x=1,y=0,a;
	int res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}
int main(){
	scanf("%d%d",&n,&s);
	while(n--){
		int x;
		scanf("%d",&x);
		if(x==3) a++;
		if(x==4) b++;
		if(x==5) c++;
	}
	for(int i=0; i*b<=s; i++){
		int p=a,q=c,r=s-i*b,x,y;
		int g=exgcd(p,q,x,y);
		p/=g;
		q/=g;
		r/=g;
		x*=r;
		y*=r;
		int mx=min(i,(r-i*q)/p);
		mx-=(mx-x%q+q*2)%q;
		if(mx>=0){
			Check(mx,i,(r-p*mx)/q);
			int t=(p*x-q*y)/(p*q*2);
			for(int j=-1; j<=1; j++)
				Check(x-q*(t+j),i,y+p*(t+j));
		}
	}
	if(ans==INF) puts("-1");
	else printf("%d %d %d\n",ax,ay,az);
	return 0;
}