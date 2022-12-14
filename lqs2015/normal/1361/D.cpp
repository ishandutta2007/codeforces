#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-10;
int n,k,cnt,num[555555];
long double x,y,ans,ax,ay;
map<pair<long double,int>,vector<pair<long double,long double> > >mp;
vector<pair<long double,long double> > v;
priority_queue<pair<long double,int> > pq;
struct line
{
	int sz;
	vector<long double> len,p0,p1,p2,suf; 
	void Init()
	{
		p0.resize(sz+1);p1.resize(sz+1);p2.resize(sz+1);suf.resize(sz+1);
		int ct=0;
		for (int i=sz-1;i>=0;i--)
		{
			ct++;
			suf[i]=suf[i+1]+len[i]*(long double)ct*(long double)(k-ct);
		}
		p0[0]=len[0];p1[0]=p2[0]=0.00;
		for (int i=1;i<sz;i++)
		{
			p0[i]=p0[i-1]+len[i];
			p1[i]=p1[i-1]+len[i]*(long double)i;
			p2[i]=p2[i-1]+len[i]*(long double)i*(long double)i;
		}
	}
	long double eval(int x)
	{
		int t=(k>>1),num;long double res=0.00;
		if (x<=t)
		{
			res=suf[sz-x];
			if (sz-x>0) res+=(p0[sz-x-1]*(long double)x*(long double)(k-x));
			return res;
		}
		num=x-t;x=k-x;
		res=-p2[num-1]+p1[num-1]*(long double)(k-2*x)+p0[num-1]*(long double)(1ll*x*k-1ll*x*x);
		res+=((p0[sz-t-1]-p0[num-1])*(long double)t*(long double)(k-t));
		res+=suf[sz-t];
		return res;
	}
}l[555555];
bool cmp(pair<long double,long double> x,pair<long double,long double> y)
{
	return (x.first*x.first+x.second*x.second<y.first*y.first+y.second*y.second);
}
int main()
{
	scanf("%d%d",&n,&k);
	ax=39.1328;ay=50.3939;
	for (int i=1;i<=n;i++)
	{
		scanf("%Lf%Lf",&x,&y);
		if (fabs(x)<eps && fabs(y)<eps) continue;
		long double tp=x*ay-y*ax;
		if (tp>eps) mp[make_pair(x/y,1)].push_back(make_pair(x,y));
		else mp[make_pair(x/y,0)].push_back(make_pair(x,y));
	}
	for (map<pair<long double,int>,vector<pair<long double,long double> > >::iterator it=mp.begin();it!=mp.end();it++)
	{
		v=it->second;
		sort(v.begin(),v.end(),cmp);
		x=y=0.00;++cnt;
		for (int i=0;i<v.size();i++)
		{
			l[cnt].sz++;
			l[cnt].len.push_back(sqrt((v[i].first-x)*(v[i].first-x)+(v[i].second-y)*(v[i].second-y)));
			x=v[i].first;y=v[i].second;
		}
		l[cnt].Init();
	}
	for (int i=1;i<=cnt;i++) pq.push(make_pair(l[i].eval(1),i));
	for (int i=1;i<k;i++)
	{
		pair<long double,int> cur=pq.top();pq.pop();
		num[cur.second]++;
		ans+=cur.first;
		if (num[cur.second]<l[cur.second].sz) 
		{
			pq.push(make_pair(l[cur.second].eval(num[cur.second]+1)-l[cur.second].eval(num[cur.second]),cur.second));
		}
	} 
	if (!pq.empty() && pq.top().first>eps) ans+=pq.top().first;
	printf("%.9Lf\n",ans);
	return 0;
}