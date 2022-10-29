#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
	point operator-(const point &k)const{return (point){x-k.x,y-k.y};}
	point unit(){int g=__gcd(x,y),p=x/g,q=y/g;if(p<0 or (p==0 and q<0))p=-p,q=-q;return (point){p,q};}
	bool operator==(const point &k)const{return x==k.x and y==k.y;}
	bool operator!=(const point &k)const{return x!=k.x or y!=k.y;}
	bool operator<(const point &k)const{return x==k.x?y<k.y:x<k.x;}
	double dis(const point &k)const{return hypot(x-k.x,y-k.y);}
}p[233333],sp,st,newp[233333];
int n,k;
bool check(int a,int b)
{
	point id=(p[a]-p[b]).unit();
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=a and i!=b)
		{
			if((p[a]-p[i]).unit()!=id)
			{
				sp=p[i];
				cnt++;
			}
		}
	}
	return cnt==1;
}
vector<int> ord;
double solve()
{
	double len=0,ret=1e18;
	for(int i=1;i<n-1;i++)
	{
		len+=newp[ord[i]].dis(newp[ord[i+1]]);
	}
	for(int i=1;i<n-1;i++)
	{
		ret=min(ret,len-newp[ord[i]].dis(newp[ord[i+1]])+sp.dis(newp[ord[i]])+sp.dis(newp[ord[i+1]]));
	}
	ret=min(ret,len+sp.dis(newp[ord[n-1]]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	st=p[k];
	int k1,k2;
	if(check(1,2))k1=1,k2=2;
	else if(check(1,3))k1=1,k2=3;
	else if(check(2,3))k1=2,k2=3;
	else assert(0);
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]!=sp)newp[++top]=p[i];
	}
	sort(newp+1,newp+n);
	if(st==sp)
	{
		cout<<fixed<<setprecision(9)<<newp[1].dis(newp[n-1])+min(sp.dis(newp[1]),sp.dis(newp[n-1]))<<endl;
	}
	else
	{
		for(int i=1;i<=n-1;i++)
		{
			if(st==newp[i])
			{
				k=i;
				break;
			}
		}
		double ans=1e18;
		if(k==1)
		{
			//1 2 3
			//1 2 3
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=2;i<=n-1;i++)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 3 2
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=n-1;i>=2;i--)
				ord.push_back(i);
			ans=min(ans,solve());
		}
		else if(k==n-1)
		{
			//3 2 1
			//1 2 3
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=n-2;i>=1;i--)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 3 2
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=1;i<=n-2;i++)
				ord.push_back(i);
			ans=min(ans,solve());
		}
		else
		{
			//3 2 1 4 5
			//1 2 3 4 5
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=k-1;i>=1;i--)
				ord.push_back(i);
			for(int i=k+1;i<=n-1;i++)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 3 2 4 5
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=1;i<=k-1;i++)
				ord.push_back(i);
			for(int i=k+1;i<=n-1;i++)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 2 3 5 4
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=k-1;i>=1;i--)
				ord.push_back(i);
			for(int i=n-1;i>=k+1;i--)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 3 2 5 4
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=1;i<=k-1;i++)
				ord.push_back(i);
			for(int i=n-1;i>=k+1;i--)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 4 5 2 3
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=k+1;i<=n-1;i++)
				ord.push_back(i);
			for(int i=k-1;i>=1;i--)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 5 4 2 3
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=n-1;i>=k+1;i--)
				ord.push_back(i);
			for(int i=k-1;i>=1;i--)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 4 5 3 2
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=k+1;i<=n-1;i++)
				ord.push_back(i);
			for(int i=1;i<=k-1;i++)
				ord.push_back(i);
			ans=min(ans,solve());
			//1 5 4 3 2
			{
				vector<int> QAQ;
				ord.swap(QAQ);
			}
			ord.push_back(0);
			ord.push_back(k);
			for(int i=n-1;i>=k+1;i--)
				ord.push_back(i);
			for(int i=1;i<=k-1;i++)
				ord.push_back(i);
			ans=min(ans,solve());
		}
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}
	return 0;
}