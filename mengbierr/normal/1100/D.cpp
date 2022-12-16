#include<bits/stdc++.h>
using namespace std;typedef long long ll;typedef pair<int,int>pii;
#define fi first
#define sc second
#define sz(a) ((int)(a).size())
#define f(i,a,b) for(int i=a;i<b;++i)
#define ff(i,a,b) for(int i=a;i<=b;++i)
#define file freopen("in.txt","r",stdin)
#define mem(a,b) memset(a,b,sizeof(a))
/*********************************************/
const int N=1e3+5;
const int m=500; 
int x,y,xx[N],yy[N],x2,y2,now,tox,toy;
int mp[N][N];
struct node {
	int num;
	int w;
}hh[4];
bool cmp(node a,node b) {return a.num<b.num;}
void tosw(int x1,int y1) {
	while(x!=x1||y!=y1) {
		if(y<y1) y++;else y--;
		if(x<x1&&mp[x+1][y]==0) x++;
		else if(x>x1&&mp[x-1][y]==0) x--;
		cout << x << ' ' << y << endl;
		cin >> now >> x2 >> y2;
		if(now<0) exit(0);
		mp[xx[now]][yy[now]]=0;
		xx[now]=x2;yy[now]=y2;
		mp[x2][y2]=1;
	}
}
int main() {
	cin >> x >> y;
	ff(i,1,666) {cin >> xx[i] >> yy[i];mp[xx[i]][yy[i]]=1;}
	tosw(m,m);
	ff(i,0,3) hh[i].w=i;
	ff(i,1,999) ff(j,1,999) if(mp[i][j]) {
		if(i<m&&j<m)	hh[0].num++;
		else if(i<m&&j>m) hh[1].num++;
		else if(i>m&&j<m) hh[2].num++;
		else hh[3].num++;
	}
	sort(hh,hh+4,cmp);
	int minn=hh[0].w;
	if(minn==0) {tox=999;toy=999;}
	else if(minn==1) {tox=999;toy=1;}
	else if(minn==2) {tox=1;toy=999;}
	else {tox=1;toy=1;};
	tosw(tox,toy);
	return 0;
}