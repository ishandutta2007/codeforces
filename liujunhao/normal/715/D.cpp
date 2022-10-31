#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long T;
void Read(long long &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
struct wall{
	int x1,y1,x2,y2;
	inline wall(){
	}
	inline wall(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){
	}
}ans[300+10];
int cnt;
int main()
{
	Read(T);
	long long a=pow(6,23)+0.5;
	int t,now=2,i,tot=50;
	printf("%d %d\n",tot,tot);
	ans[++cnt]=wall(1,2,2,2);
	ans[++cnt]=wall(2,1,2,2);
	while(a){
		t=T/a;
		T-=t*a;
		a/=6;
		now+=2;
		ans[++cnt]=wall(now-3,now-1,now-2,now-1);
		if(now!=tot){
			if(now!=4){
				ans[++cnt]=wall(now-4,now+1,now-3,now+1);
				ans[++cnt]=wall(now+1,now-4,now+1,now-3);
			}
			ans[++cnt]=wall(now-2,now,now-2,now+1);
			ans[++cnt]=wall(now-1,now,now-1,now+1);
			ans[++cnt]=wall(now-2,now+2,now-1,now+2);
			ans[++cnt]=wall(now,now-1,now+1,now-1);
			ans[++cnt]=wall(now,now-2,now+1,now-2);
			ans[++cnt]=wall(now+2,now-2,now+2,now-1);
		}
		if(t%3==0)
			ans[++cnt]=wall(now-3,now,now-2,now);
		if(t%3<=1)
			ans[++cnt]=wall(now,now-3,now,now-2);
		if(t<3)
			ans[++cnt]=wall(now-1,now-3,now-1,now-2);
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
}