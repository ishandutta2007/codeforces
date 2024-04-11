#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct st
{
	int t;
	int ind;
};
struct se
{
	int t;
	int ind;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//262144
//524288
priority_queue<st> s;
priority_queue<se> u;
//int bit[524288];
//int d[524288][3];
bool koristi[262144];
bool prosao[262144];
int a[262144];
int t[262144];
long long int n,k;
int r=0;
long long int d=0;
int p,q;
long long int w=0;
int v=0;
bool operator >(st x,st y)
{
	return x.t>y.t;
}
bool operator <(st x,st y)
{
	return x.t<y.t;
}
bool operator <(se x,se y)
{
	return x.t>y.t;
}
bool operator >(se x,se y)
{
	return x.t<y.t;
}
int main()
{
	cin>>n>>w>>k;
	for(int i=0;i<262144;i++) 
	{
		a[i]=0;
		koristi[i]=false;
		prosao[i]=false;
	}
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&t[i]);
	/*for(int i=262143;i<524288;i++)
	{
		bit[i]=a[i-262143];
		d[i][0]=i-262143;
		d[i][1]=i-262143;
		d[i][2]=i-262143;
	}
	for(int i=262142;i>=0;i--)
	{
		bit[i]=a[i*2+2];
		d[i][1]=d[i*2+2][1];
		d[i][0]=d[i*2+1][0];
		d[i][2]=d[i*2+1][1];
		if(a[i*2+1]>bit[i]) bit[i]=a[i*2+1];
	}*/
	st pom;
	se qom;
	p=0;
	int ut,st;
	int u1=0,s1=0;
	q=-1;
	int maxr=0;
	while(p<n && q<n)
	{
		if(q+1<n)
		{
			if(d<=k)
			{
				q++;
				d+=t[q];
				pom.t=t[q];
				pom.ind=q;
				s.push(pom);
				s1++;
				r+=a[q];
			}
			//cout<<p<<" "<<q<<" "<<d<<" "<<endl;
			//cout<<u1<<" "<<s1<<endl;;
			//cout<<p<<" "<<q<<" "<<d<<" "<<r<<" "<<v<<" "<<s.top().t<<endl;
			
			while(v<w && s1>0)
			{
				pom=s.top();
				if(!prosao[pom.ind])
				{
					qom.ind=pom.ind;
					qom.t=pom.t;
					koristi[pom.ind]=true;
					d-=pom.t/2;
					u.push(qom);
					u1++;
					v++;
				}
				s.pop();
				s1--;
			}
			while(s.size()>0)
			{
				pom=s.top();
				if(!prosao[pom.ind])
				{
					break;
				}
				s.pop();
				s1--;
			}
			if(u1>0) ut=(u.top().t)/2;
			if(s1>0) st=(s.top().t)/2;
			while(u1>0 && s1>0 && ut<st)
			{
				//cout<<q<<endl;
				d+=ut;
				d-=st;
				koristi[u.top().ind]=false;
				koristi[s.top().ind]=true;
				qom=u.top();
				pom.ind=qom.ind;
				pom.t=qom.t;
				s.push(pom);
				u.pop();
				pom=s.top();
				s.pop();
				qom.ind=pom.ind;
				qom.t=pom.t;
				u.push(qom);
				while(s.size()>0)
				{
					pom=s.top();
					if(!prosao[pom.ind])
					{
						break;
					}
					s.pop();
					s1--;
				}
				while(u.size()>0)
				{
					qom=u.top();
					if(koristi[qom.ind])
					{
						break;
					}
					u.pop();	
					u1--;
				}
				if(u1>0) ut=(u.top().t)/2;
				if(s1>0) st=(s.top().t)/2;
			}
			//cout<<p<<" "<<q<<" "<<d<<" "<<r<<" "<<v<<" "<<s.top().t<<" "<<s1<<endl;
			if(d>k)
			{
				r-=a[p];
				d-=t[p];
				prosao[p]=true;
				if(koristi[p])
				{
					d=d+t[p]/2;
					koristi[p]=false;
					v--;
				}
				p++;
			}
			//cout<<p<<" "<<q<<" "<<d<<" "<<r<<" "<<v<<" "<<s.top().t<<endl;
			if(r>maxr && d<=k) maxr=r;
			while(s.size()>0)
			{
				pom=s.top();
				if(!prosao[pom.ind])
				{
					break;
				}
				s.pop();
				s1--;
			}
			while(u.size()>0)
			{
				qom=u.top();
				if(koristi[qom.ind])
				{
					break;
				}
				u.pop();	
				u1--;
			}
		}
		else q++;
	}
	printf("%d",maxr);
	return 0;
}