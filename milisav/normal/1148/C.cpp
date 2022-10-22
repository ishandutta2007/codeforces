#include<bits/stdc++.h>
using namespace std;
int n;
int p[400000];
int l[400000];
vector<pair<int,int> > swp;
void add_swap(int a,int b) {
	swp.push_back({a,b});
	swap(p[a],p[b]);
	l[p[a]]=a;
	l[p[b]]=b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
		l[p[i]]=i;
	}
	for(int i=1;i<=n/2;i++) {
		int a=n/2+i;
		int t;
		int c=l[a];
		if(c>n/2) t=1;
		else t=n;
		add_swap(c,t);
		if(t==n) add_swap(t,1);
		add_swap(1,a);
		a=n/2-i+1;
		c=l[a];
		if(c>n/2) t=1;
		else t=n;
		add_swap(c,t);
		if(t==1) add_swap(t,n);
		add_swap(n,a);
	}
	printf("%d\n",swp.size());
	for(int i=0;i<swp.size();i++) printf("%d %d\n",swp[i].first,swp[i].second);
	return 0;
}