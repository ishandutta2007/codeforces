#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> x[200000];
pair<int,int> y[200000];
vector<int> px;
vector<int> py;
vector<pair<int,int> > s;
int prip(int u,int v) {
	int t=0;
	for(int i=0;i<n;i++) {
		if(x[i].first<=u && u<=x[i].second && y[i].first<=v && v<=y[i].second) t++;
	}
	return t;
}
int main()
{
	int u1,v1,u2,v2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&u1,&v1,&u2,&v2);
		x[i]=make_pair(u1,u2);
		y[i]=make_pair(v1,v2);
		s.push_back(make_pair(u1,-1));
		s.push_back(make_pair(u2,1));
	}
	int t=0;
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++) {
		t-=s[i].second;
		if(t>=n-1) px.push_back(s[i].first);
	}
	s.clear();
	for(int i=0;i<n;i++) {
		s.push_back(make_pair(y[i].first,-1));
		s.push_back(make_pair(y[i].second,1));
	}
	t=0;
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++) {
		t-=s[i].second;
		if(t>=n-1) py.push_back(s[i].first);
	}
	s.clear();
	for(int i=0;i<px.size();i++) {
		for(int j=0;j<py.size();j++) {
			if(prip(px[i],py[j])>=n-1) {
				printf("%d %d",px[i],py[j]);
				return 0;
			}
		}
	}
	return 0;
}