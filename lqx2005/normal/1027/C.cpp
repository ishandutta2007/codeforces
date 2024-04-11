#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int T,n;
int num;
map<int,int> cnt;
double Calc(int a,int b)
{
	double p=2*(a+b);
	double s=a*b;
	return p*p/s;
}
int main()
{
	scanf("%d",&T);
	for(int tot=1;tot<=T;tot++)
	{
		scanf("%d",&n);
		cnt.clear();
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&num);
			cnt[num]++;
		}
		int pos1=-1,pos2=-1;
		int last=-1,flag=0;
		map<int,int>::iterator it;
		for(it=cnt.begin();it!=cnt.end();it++)
		{
			int i=it->first;
			if(cnt[i]>=4)
			{
				flag=1;
				printf("%d %d %d %d\n",i,i,i,i);
				break;
			}
			if(cnt[i]<=1) continue;
			if(last!=-1)
			{
				if(pos1==-1&&pos2==-1) pos1=i,pos2=last;
				else 
				{
					if(Calc(pos1,pos2)>Calc(last,i)) pos1=last,pos2=i;
				}	
			}
			last=i;
		}
		if(!flag)
		{
			printf("%d %d %d %d\n",pos1,pos1,pos2,pos2);
			continue;
		}
	}
	return 0;
}