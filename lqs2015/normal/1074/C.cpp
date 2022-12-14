#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,x[333333],y[333333],xmax,xmin,ymax,ymin,ans,xm,xi,ym,yi;
vector<int> mxx,mnx,mxy,mny;
vector<pair<int,int> > v;
int main()
{
	scanf("%d",&n);
	xmin=ymin=1e9;xmax=ymax=-1e9;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		xmax=max(xmax,x[i]);xmin=min(xmin,x[i]);
		ymax=max(ymax,y[i]);ymin=min(ymin,y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (x[i]==xmax) mxx.push_back(y[i]);
		else if (x[i]==xmin) mnx.push_back(y[i]);
		if (y[i]==ymax) mxy.push_back(x[i]);
		else if (y[i]==ymin) mny.push_back(x[i]);    
	}
	sort(mxx.begin(),mxx.end());
	sort(mxy.begin(),mxy.end());
	sort(mnx.begin(),mnx.end());
	sort(mny.begin(),mny.end());
	v.push_back(make_pair(xmax,mxx[0]));v.push_back(make_pair(xmax,mxx[(int)mxx.size()-1])); 
	v.push_back(make_pair(xmin,mnx[0]));v.push_back(make_pair(xmin,mnx[(int)mnx.size()-1]));
	v.push_back(make_pair(mxy[0],ymax));v.push_back(make_pair(mxy[(int)mxy.size()-1],ymax));
	v.push_back(make_pair(mny[0],ymin));v.push_back(make_pair(mny[(int)mny.size()-1],ymin));
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	if (v.size()<=2)
	{
		ans=xmax-xmin+ymax-ymin;
	}
	else
	{
		for (int i=0;i<v.size();i++)
		{
			for (int j=i+1;j<v.size();j++)
			{
				for (int k=1;k<=n;k++)
				{
					if (x[k]==v[i].first && y[k]==v[i].second) continue;
					if (x[k]==v[j].first && y[k]==v[j].second) continue;
					xm=max(v[i].first,max(v[j].first,x[k]));
					xi=min(v[i].first,min(v[j].first,x[k]));
					ym=max(v[i].second,max(v[j].second,y[k]));
					yi=min(v[i].second,min(v[j].second,y[k]));
					ans=max(ans,xm-xi+ym-yi);
				}
			}
		}
	}
	printf("%d ",ans*2);
	for (int i=4;i<=n;i++) printf("%d ",2*(xmax-xmin+ymax-ymin));
	printf("\n");
	return 0;
}