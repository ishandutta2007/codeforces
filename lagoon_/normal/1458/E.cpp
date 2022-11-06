#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
int x[200010],y[200010],a[100100],b[100100];
const ull B=1e9+11;
std::map<ull,int>px,py,pn;
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		std::map<ull,int>::iterator it;
		if(!px[x[i]])px[x[i]]=y[i]+1;
		else px[x[i]]=std::min(px[x[i]],y[i]+1);
		if(!py[y[i]])py[y[i]]=x[i]+1;
		else py[y[i]]=std::min(py[y[i]],x[i]+1);
		pn[x[i]*B+y[i]]=1;
	}
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		x[++n]=a[i];y[n]=b[i];
	}
	n++;
	x[n]=y[n]=1<<30;
	std::sort(x+1,x+n+1);
	std::sort(y+1,y+n+1);
	for(re int i=0,j=0;i<=1e9;)
	{
		re int xx=std::min((*std::lower_bound(y+1,y+n+1,j))-j,(*std::lower_bound(x+1,x+n+1,i))-i);
		i+=xx;j+=xx;
		while(py[j]&&py[j]-1<=i)j++;
		if(px[i]&&px[i]-1<=j)
		{
			i++;
		}
		else
		{
			pn[i*B+j]=1;
			i++;j++;
		}
	}
	for(re int i=1;i<=m;i++)
	{
		if(pn[a[i]*B+b[i]])puts("LOSE");
		else puts("WIN");
	}
}