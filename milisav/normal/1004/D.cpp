#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int b[2000000];
int c[2000000];
int n,m;
int t;
vector<vector<int> > p;
vector<pair<int,int> > d;
vector<int> q;
bool test(int x,int y) {
	if(x<0 || x>=n) return false;
	if(y<0 || y>=m) return false;
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) p[i][j]=t+1;
	}
	p[x][y]=0;
	int ind=0;
	d.clear();
	d.push_back(make_pair(x,y));
	while(ind<d.size()) {
		x=d[ind].first;
		y=d[ind].second;
		if(x-1>=0 && p[x-1][y]>p[x][y]+1) {
			p[x-1][y]=p[x][y]+1;
			d.push_back(make_pair(x-1,y));
		}
		if(x+1<n && p[x+1][y]>p[x][y]+1) {
			p[x+1][y]=p[x][y]+1;
			d.push_back(make_pair(x+1,y));
		}
		if(y-1>=0 && p[x][y-1]>p[x][y]+1) {
			p[x][y-1]=p[x][y]+1;
			d.push_back(make_pair(x,y-1));
		}
		if(y+1<m && p[x][y+1]>p[x][y]+1) {
			p[x][y+1]=p[x][y]+1;
			d.push_back(make_pair(x,y+1));
		}
		ind++;
	}
	for(int i=0;i<t;i++) c[i]=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			c[p[i][j]]++;
			//cout<<p[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=0;i<t;i++) if(c[i]!=b[i]) return false;
	return true;
}
int x,y;
bool pos() {
	int k=1;
	int l;
	q.clear();
	for(int i=0;i<m;i++) q.push_back(0);
	p.clear();
	for(int i=0;i<n;i++) p.push_back(q);
	for(int i=a[t-1];i>=0;i--) {
		l=k;
		l=min(l,min(n,m));
		if(b[i]>l) {
			x=(k-1+n-1)/2;
			y=a[t-1]-x;
			//cout<<x<<" "<<y<<endl;
			if(test(x,y)) return true;
			y=(k-1+m-1)/2;
			x=a[t-1]-y;
			//cout<<x<<" "<<y<<endl;
			if(test(x,y)) return true;
			return false;
		}
		k++;
	}
	if(test(0,0)) {
		x=0;
		y=0;
		return true;
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++) scanf("%d",&a[i]);
	sort(a,a+t);
	for(int i=0;i<t;i++) b[a[i]]++;
	n=4;
	m=5;
	pos();
	for(int i=1;i*i<=t;i++) {
		if(t%i==0) {
			n=i;
			m=t/i;
			//cout<<n<<" "<<m<<endl;
			if(pos()) {
				printf("%d %d\n",n,m);
				printf("%d %d\n",x+1,y+1);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}