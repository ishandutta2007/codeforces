#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6005,inf=0x3f3f3f3f;
int n,lst;
ll cnt;
int a[N][3];
int red[N];
int q[N],k,w;
deque<int> dQ,dQ2;
int pos[N];
int qb,qe;
inline void run()
{
	cnt++;
	if(a[q[k]][w]>a[q[(k+1)%n]][0])
	{
		if(++w==3)
			printf("%d %lld\n",q[k],cnt),exit(0);
		else
			swap(q[k],q[(k+1)%n]),k=(k+1)%n;
	}
	else
		w=1,k=(k+1)%n;
	return;
}
int len;
inline void insert_f(int k)
{
	qb--;
	while(!dQ.empty()&&a[k][1]<dQ.front())
		dQ.pop_front(),dQ2.pop_front(),len--;
	dQ.push_front(a[k][1]);dQ2.push_front(qb);len++;
	return;
}
inline void erase_b(int k)
{
	qe--;
	if(!dQ.empty()&&dQ.back()==a[k][1])
		dQ.pop_back(),dQ2.pop_back(),len--;
	return;
}
inline bool chaos()
{
	int d,y,epc=inf;
	register int i;
	while(w!=1)
		run();
	lst=-1;
	memset(red,0,sizeof(int)*n);
	for(i=0;i<n;i++)
		if(a[q[i]][0]<a[q[(i+n-1)%n]][1])
			red[q[i]]=1,lst=i;
	if(!~lst)
		return 0;
	for(i=(lst+n-1)%n,d=0;i!=lst;i=(i+n-1)%n)
		if(red[q[i]])
			d=0;
		else
		{
			if(red[q[(i+1)%n]])
				y=q[(i+2)%n];
			else
				y=q[(i+1)%n];
				if(a[q[i]][2]>a[y][0])
					epc=min(epc,d);
			d++;
		}
	qb=qe=0;dQ.clear();len=0;
	for(i=(lst+1)%n;i!=lst;i=(i+1)%n)
		if(!red[q[i]])
			insert_f(q[i]);
	deque<int>::iterator it;
	if((it=upper_bound(dQ.begin(),dQ.end(),a[q[lst]][0],greater<int>()))!=dQ.end())
		epc=min(epc,dQ2[it-dQ.begin()]-qb);
	for(i=(lst+1)%n;i!=lst;i=(i+1)%n)
		if(red[q[i]])
		{
			if((it=upper_bound(dQ.begin(),dQ.end(),a[q[i]][0],greater<int>()))!=dQ.end())
				epc=min(epc,dQ2[it-dQ.begin()]-qb);
		}
		else
			erase_b(q[i]),insert_f(q[i]);
	if(epc==inf)
		return 0;
	int _r=0,_=0,xx=(lst+n-1)%n,yy;
	if(epc==0)
		goto end1;
	for(yy=lst;_<epc;yy=(yy+1)%n)
		if(!red[q[yy]])
		{
			if(++_==epc)
				break;
		}
		else
			_r++;
	pos[q[xx]]=(xx+_r)%n;
	for(i=lst;i!=xx;i=(i+1)%n)
		if(!red[q[i]])
		{
			_--;
			for(yy=(yy+1)%n;_<epc;yy=(yy+1)%n)
			{
				if(!red[q[yy]])
				{
					if(++_==epc)
						break;
				}
				else
					_r++;
			}
			pos[q[i]]=(i+_r)%n;
		}
		else
			_r--;
	for(i=0;i<n;i++)
		if(red[q[i]])
			pos[q[i]]=(i-epc+n)%n;
	for(i=0;i<n;i++)
		q[pos[i]]=i;
	k=(k-epc+n)%n;
	if(epc)
	{
		if(red[q[(k+n-1)%n]])
			w=2;
		else
			w=1;
	}
	cnt+=(ll)epc*(n-1);
	end1:;
	for(i=0;i<n;i++)
		run();
	return 1;
}
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	for(i=0;i<n;i++)
		q[i]=i;
	for(i=1;i<=36;i++)
		run();
	while(chaos())
		len++,len--;
	puts("-1 -1");
	return 0;
}