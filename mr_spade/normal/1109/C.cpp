#include<cstdio>
#include<algorithm>
#define int long long
#define random Mr_Spade
using std::max;
inline int random()
{
	static int x=1984;
	return x^=x<<13,x^=x>>17,x^=x<<7,x;
}
const int N=1e5+5;
int q;
int root,tot;
struct node
{
	int prio;
	int t,s;
	int tl,tr,sr;
	int res,Min;
	int ch[2];
}t[N];
inline void push_up(int x)
{
	if(t[x].ch[0])
		t[x].tl=t[t[x].ch[0]].tl;
	else
		t[x].tl=t[x].t;
	if(t[x].ch[1])
		t[x].tr=t[t[x].ch[1]].tr,t[x].sr=t[t[x].ch[1]].sr;
	else
		t[x].tr=t[x].t,t[x].sr=t[x].s;
	t[x].res=0;t[x].Min=0;
	if(t[x].ch[0])
	{
		t[x].Min=max(t[x].Min,t[t[x].ch[0]].Min);t[x].res+=t[t[x].ch[0]].res;
		t[x].res+=t[t[x].ch[0]].sr*(t[x].t-t[t[x].ch[0]].tr);t[x].Min=max(t[x].Min,-t[x].res);
	}
	if(t[x].ch[1])
	{
		t[x].res+=t[x].s*(t[t[x].ch[1]].tl-t[x].t);t[x].Min=max(t[x].Min,-t[x].res);
		t[x].Min=max(t[x].Min,t[t[x].ch[1]].Min-t[x].res);t[x].res+=t[t[x].ch[1]].res;
	}
	return;
}
void split(int now,int &x,int &y,int k)
{
	if(!now)
		return x=y=0,void();
	if(t[now].t<=k)
		x=now,split(t[now].ch[1],t[now].ch[1],y,k);
	else
		y=now,split(t[now].ch[0],x,t[now].ch[0],k);
	push_up(now);
	return;
}
int merge(int x,int y)
{
	if(!x||!y)
		return x^y;
	if(t[x].prio<t[y].prio)
		return t[x].ch[1]=merge(t[x].ch[1],y),push_up(x),x;
	else
		return t[y].ch[0]=merge(x,t[y].ch[0]),push_up(y),y;
}
double query(int x,int w)
{
	if(t[x].ch[0])
	{
		if(w<=t[t[x].ch[0]].Min)
			return query(t[x].ch[0],w);
		w+=t[t[x].ch[0]].res;
		if(w+t[t[x].ch[0]].sr*(t[x].t-t[t[x].ch[0]].tr)<=0)
			return t[t[x].ch[0]].tr-(double)w/t[t[x].ch[0]].sr;
		w+=t[t[x].ch[0]].sr*(t[x].t-t[t[x].ch[0]].tr);
	}
	if(t[x].ch[1])
	{
		if(w+t[x].s*(t[t[x].ch[1]].tl-t[x].t)<=0)
			return t[x].t-(double)w/t[x].s;
		w+=t[x].s*(t[t[x].ch[1]].tl-t[x].t);
		return query(t[x].ch[1],w);
	}
	return t[x].t-(double)w/t[x].s;
}
signed main()
{
	int opt,l,r,x;
	int dx,dy,dz,dw;
	register int i;
	for(i=1;i<=100000;i++)
		t[i].prio=random();
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&opt);
		if(opt==1)
		{
			scanf("%lld%lld",&l,&x);
			split(root,dx,dy,l);
			tot++;
			t[tot].t=l;t[tot].s=x;
			t[tot].tl=t[tot].t;
			t[tot].tr=t[tot].t;
			t[tot].sr=t[tot].s;
			t[tot].res=t[tot].Min=0;
			t[tot].ch[0]=t[tot].ch[1]=0;
			root=merge(merge(dx,tot),dy);
		}
		else if(opt==2)
		{
			scanf("%lld",&l);
			split(root,dx,dy,l);
			split(dx,dz,dw,l-1);
			root=merge(dz,dy);
		}
		else
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			split(root,dx,dy,r);
			split(dx,dz,dw,l-1);
			if(x==0)
			{
				printf("%.8lf\n",(double)l);
				root=merge(merge(dz,dw),dy);
				continue;
			} 
			if(!dw)
			{
				puts("-1");
				root=merge(merge(dz,dw),dy);
				continue;
			}
			if(x>t[dw].Min)
			{
				x+=t[dw].res;
				if(x+(r-t[dw].tr)*t[dw].sr<=0)
					printf("%.8lf\n",t[dw].tr-(double)x/t[dw].sr);
				else
					puts("-1");
			}
			else
				printf("%.8lf\n",query(dw,x));
			root=merge(merge(dz,dw),dy);
		}
	}
	return 0;
}