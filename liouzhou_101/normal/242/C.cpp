#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MaxN=100010;
const int INF=1000000000;

int sx,sy,tx,ty,n;
vector<pair<int,int> > p;
queue<pair<int,int> > Q;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int F[MaxN];

int main()
{
	cin>>sx>>sy>>tx>>ty;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x,L,R;
		scanf("%d%d%d",&x,&L,&R);
		for (int j=L;j<=R;++j)
			p.push_back(make_pair(x,j));
	}
	sort(p.begin(),p.end());
	for (int i=0;i<p.size();++i)
		F[i]=INF;
	Q.push(make_pair(sx,sy));
	F[lower_bound(p.begin(),p.end(),make_pair(sx,sy))-p.begin()]=0;
	while (!Q.empty())
	{
		pair<int,int> now=Q.front();
		Q.pop();
		int A=lower_bound(p.begin(),p.end(),now)-p.begin();
		for (int k=0;k<8;++k)
		{
			int x=now.first+dx[k],y=now.second+dy[k];
			int B=lower_bound(p.begin(),p.end(),make_pair(x,y))-p.begin();
			if (p[B]==make_pair(x,y))
				if (F[B]>F[A]+1)
				{
					F[B]=F[A]+1;
					Q.push(p[B]);
				}
		}
	}
	if (F[lower_bound(p.begin(),p.end(),make_pair(tx,ty))-p.begin()]==INF)
		cout<<-1<<endl;
	else
		cout<<F[lower_bound(p.begin(),p.end(),make_pair(tx,ty))-p.begin()]<<endl;
	return 0;
}