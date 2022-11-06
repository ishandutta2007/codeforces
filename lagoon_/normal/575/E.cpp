#include<bits/stdc++.h>
using namespace std;
#define re register
struct poi{int x,y;}po[800100];
inline bool cmp(const poi&A,const poi&B){return A.x==B.x?A.y<B.y:A.x<B.x;}
int q[160010],ta;
bool caj(re int a,re int b,re int c)
{
	return (long long)(po[c].y-po[a].y)*(po[a].x-po[b].x)<=(long long)(po[a].y-po[b].y)*(po[c].x-po[a].x);
}
long double ans;
int b1,b2,b3;
void cal(re int a1,re int a2,re int a3)
{
	#define lb long double
	re long double a=2*(po[a1].x-po[a3].x),b=2*(po[a1].y-po[a3].y),c=(lb)po[a1].x*po[a1].x-(lb)po[a3].x*po[a3].x+(lb)po[a1].y*po[a1].y-(lb)po[a3].y*po[a3].y;
	re long double d=2*(po[a2].x-po[a3].x),e=2*(po[a2].y-po[a3].y),f=(lb)po[a2].x*po[a2].x-(lb)po[a3].x*po[a3].x+(lb)po[a2].y*po[a2].y-(lb)po[a3].y*po[a3].y;
	re long double y=(a*f-c*d)/(a*e-b*d),x=(c-b*y)/a,r=sqrt((x-po[a1].x)*(x-po[a1].x)+(y-po[a1].y)*(y-po[a1].y));
	if(r>ans)ans=r,b1=a1,b2=a2,b3=a3;
}
int main()
{
	re int n,x,y,v,n1=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		if(x>=v)po[++n1]=(poi){x-v,y};
		else po[++n1]=(poi){0,y-v+x},po[++n1]=(poi){0,y+v-x};
		if(y>=v)po[++n1]=(poi){x,y-v};
		else po[++n1]=(poi){x-v+y,0},po[++n1]=(poi){x+v-y,0};
		if(x+v<=100000)po[++n1]=(poi){x+v,y};
		else po[++n1]=(poi){100000,y+x+v-100000},po[++n1]=(poi){100000,y+100000-x-v};
		if(y+v<=100000)po[++n1]=(poi){x,y+v};
		else po[++n1]=(poi){x+v+y-100000,100000},po[++n1]=(poi){x+100000-y-v,100000};
	}
	for(re int i=1;i<=n1;i++)
	{
		po[i].x=min(max(po[i].x,0),100000);
		po[i].y=min(max(po[i].y,0),100000);
	}
	sort(po+1,po+n1+1,cmp);
	for(re int i=1;i<=n1;i++)
	{//printf("**%d %d %d\n",i,po[i].x,po[i].y);
		if(i>1&&po[i-1].x==po[i].x&&po[i-1].y==po[i].y)continue;
		while(ta>=2&&caj(q[ta],q[ta-1],i))ta--;
		q[++ta]=i;
	}
	re int ta1=ta;
	for(re int i=n1-1;i;i--)
	{
		if(po[i+1].x==po[i].x&&po[i+1].y==po[i].y)continue;
		while(ta>ta1&&caj(q[ta],q[ta-1],i))ta--;
		q[++ta]=i;
	}
	ta--;
	for(re int i=1;i<=ta;i++)
	{
		cal(q[i],q[i%ta+1],q[(i+1)%ta+1]);
	}
	printf("%d %d\n%d %d\n%d %d\n",po[b1].x,po[b1].y,po[b2].x,po[b2].y,po[b3].x,po[b3].y);
}