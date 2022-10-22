#include<bits/stdc++.h>
using namespace std;
int inf=1e9;
int n,k;
vector<pair<int,int> > a[200000];
int l[200000];
int p[200000];
int r[200000];
bool s[200000];
priority_queue<pair<int,int> > q;
int m;
void dfs(int u) {
	int v,d;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i].first;
		d=a[u][i].second;
		if(l[v]>l[u]+d) {
			l[v]=l[u]+d;
			p[v]=u;
			dfs(v);
		}
	}
}
int diameter(int u) {
	dfs(u);
	int f=0;
	for(int i=0;i<n;i++) {
		if(l[i]>l[f]) f=i;
	}
	return f;
}
int main()
{
	int u,v,d;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n-1;i++) {
		scanf("%d %d %d",&u,&v,&d);
		u--;
		v--;
		a[u].push_back(make_pair(v,d));
		a[v].push_back(make_pair(u,d));
	}
	for(int i=0;i<n;i++) l[i]=inf;
	l[0]=0;
	u=diameter(0);
	for(int i=0;i<n;i++) l[i]=inf;
	l[u]=0;
	v=diameter(u);
	d=v;
	r[m]=d;
	m++;
	while(d!=u) {
		d=p[d];
		r[m]=d;
		m++;
	}
	int c=0;
	for(int i=0;i<m;i++) {
		if(max(l[v]-l[r[i]],l[r[i]])<max(l[v]-l[r[c]],l[r[c]])) c=i;
	}
	int g=0,h=k-1;
	if(k>=m) {
		g=0;
		h=m-1;
	}
	for(int i=0;i+k-1<m;i++) {
		if(max(l[v]-l[r[i]],l[r[i+k-1]])<max(l[v]-l[r[g]],l[r[h]])) {
			g=i;
			h=i+k-1;
		}
	}
	/*g=c;
	h=c;
	while(h-g+1<k && h-g+1<m) {
		if(g==0) h++;
		else {
			if(h==m-1) g--;
			else {
				if(l[r[h+1]]<l[v]-l[r[g-1]]) g--;
				else h++; 
			}
		}
	}*/
	for(int i=0;i<n;i++) l[i]=inf;
	for(int i=g;i<=h;i++) {
		//cout<<r[i]<<endl;
		//s[r[i]]=true;
		l[r[i]]=0;
	}
	for(int i=g;i<=h;i++) {
		dfs(r[i]);
	}
	m=l[0];
	for(int i=0;i<n;i++) m=max(m,l[i]);
	printf("%d",m);
	return 0;
}