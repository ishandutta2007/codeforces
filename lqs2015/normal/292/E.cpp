#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=400;
struct pack
{
	int l,r,k;
};
pack make(int l,int r,int k)
{
	pack a;
	a.l=l;a.r=r;a.k=k;
	return a;
}
int a[111111],b[111111],n,m,tp,k,x,y,bb,l,r,z,lx,ly,rb,lb;
vector<pack> buc[266];
bool f;
void doit(int bb,int l,int r,int z)
{
	for (int i=0;i<buc[bb].size();i++)
	{
		int ll=buc[bb][i].l,rr=buc[bb][i].r;
		if (l<=ll && r>=rr) buc[bb].erase(buc[bb].begin()+i);
	}
	buc[bb].push_back(make(l,r,z)); 
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	while(m--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			z=x-y;lx=y;ly=y+k-1;
			lb=(lx-1)/mod+1;rb=(ly-1)/mod+1;
			if (lb==rb)
			{
				doit(lb,lx,ly,z);
			}
			else
			{
				doit(lb,lx,lb*mod,z);
				doit(rb,(rb-1)*mod+1,ly,z);
			}
			for (int i=lb+1;i<=rb-1;i++)
			{
				buc[i].clear();
				buc[i].push_back(make((i-1)*mod+1,i*mod,z)); 
			}
		}
		else
		{
			scanf("%d",&x);
			f=0;
			bb=(x-1)/mod+1;
			if (buc[bb].empty()) 
			{
				printf("%d\n",b[x]);
			}
			else
			{
				for (int i=buc[bb].size()-1;i>=0;i--)
				{
					int l=buc[bb][i].l,r=buc[bb][i].r,z=buc[bb][i].k;
					if (x>=l && x<=r) 
					{
						printf("%d\n",a[x+z]);
						f=1;
						break;
					}
				}
				if (!f) printf("%d\n",b[x]);
			}
		}
	}
	return 0;
}