#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
const int MAXN=100001;
const int MAXK=301;
struct QQ
{
	int x,l,r,ql,qr,type;
	QQ(){}
	QQ(int _x,int _l,int _r,int _type):
		x(_x),l(_l),r(_r),type(_type){}
	friend bool operator<(const QQ &p,const QQ &q)
	{
		return p.x<q.x;
	}
}Q[MAXN*2];
pair<int,int> P[MAXN];
vector<int> last,res;
int n,k,tot;
long long ans[MAXN];
vector<int> vec;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d%d",&P[i].first,&P[i].second);
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			vec.push_back(P[i].second-j);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n;i++)
	{
		Q[++tot]=QQ(P[i].first-k+1,P[i].second-k+1,P[i].second,1);
		Q[++tot]=QQ(P[i].first+1,P[i].second-k+1,P[i].second,-1);
	}
	sort(Q+1,Q+tot+1);
	for(int i=1;i<=tot;i++)
	{
		Q[i].ql=lower_bound(vec.begin(),vec.end(),Q[i].l)-vec.begin();
		Q[i].qr=upper_bound(vec.begin(),vec.end(),Q[i].r)-vec.begin()-1;
	}
	int sz=vec.size();
	vec.erase(vec.begin(),vec.end());
	vec.shrink_to_fit();
	last=vector<int>(sz+1);
	res=vector<int>(sz+1);
	for(int i=1;i<=tot;i++)
		for(int j=Q[i].ql;j<=Q[i].qr;j++)
		{
			ans[res[j]]+=Q[i].x-last[j];
			res[j]+=Q[i].type;
			last[j]=Q[i].x;
		}
	for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}