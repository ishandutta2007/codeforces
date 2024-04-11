#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
#define DB long double
using namespace std;
const int N=2e3+10;
const DB inf=1e18;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m;
struct edge{
	int x[2],y;
}e[N];
bool cmp(edge A,edge B){
	return A.y<B.y;
}
DB ans1,ans2;
vector< pair<DB,int> > p;
vector<DB>p2,mn,mx;
struct P{
	int x,y;
	P(int xx=0,int yy=0){x=xx;y=yy;}
}lu,rd,a[N<<1];
P operator - (P A,P B){
	return P(A.x-B.x,A.y-B.y);
}
LL cha(P A,P B){
	return (LL)B.y*A.x-(LL)A.y*B.x;
}
bool cmpa(P A,P B){
	if(atan2(A.y-a[1].y,A.x-a[1].x)!=atan2(B.y-a[1].y,B.x-a[1].x))
	return atan2(A.y-a[1].y,A.x-a[1].x)>atan2(B.y-a[1].y,B.x-a[1].x);
	if(A.y!=B.y) return A.y>B.y;
	return A.x<B.x;
}

int main(){
	int cnt=0;
	scanf("%d",&n);m=0;
	lu.x=2e9;lu.y=-2e9;rd.x=-2e9;rd.y=2e9;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&e[i].x[0],&e[i].x[1],&e[i].y);
		++m;a[m].x=e[i].x[0];a[m].y=e[i].y;
		if(a[m].y>lu.y||(a[m].y==lu.y&&a[m].x<lu.x)) lu=a[m];
		if(a[m].y<rd.y||(a[m].y==rd.y&&a[m].x>rd.x)) rd=a[m];
		++m;a[m].x=e[i].x[1];a[m].y=e[i].y;
		if(a[m].y>lu.y||(a[m].y==lu.y&&a[m].x<lu.x)) lu=a[m];
		if(a[m].y<rd.y||(a[m].y==rd.y&&a[m].x>rd.x)) rd=a[m];
	}
	for(int i=1;i<=m;++i){
		if(a[i].x==lu.x&&a[i].y==lu.y){
			swap(a[i],a[1]);
			break;
		}
	}
	sort(a+2,a+m+1,cmpa);
	cnt=2;
	for(int i=3;i<=m;++i){
		while((cnt>=2&&cha(a[i]-a[cnt-1],a[cnt]-a[cnt-1])==0)||
		(cnt>=3&&cha(a[i]-a[cnt-2],a[cnt]-a[cnt-2])+cha(a[cnt]-a[cnt-2],a[cnt-1]-a[cnt-2])<=cha(a[i]-a[cnt-2],a[cnt-1]-a[cnt-2]))) --cnt;
		a[++cnt]=a[i];
	}
	if(cnt>=3&&cha(a[cnt]-a[1],a[cnt-1]-a[1])==0) --cnt; 
	m=cnt;a[m+1]=a[1];
	//for(int i=1;i<=m;++i) cout<<a[i].x<<" "<<a[i].y<<endl;
	sort(e+1,e+1+n,cmp);
	DB l=inf,r=-inf;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(e[i].y==e[j].y) continue;
			//cout<<(DB)(e[i].x[0]-e[j].x[1])/(DB)(e[j].y-e[i].y)<<" "<<(DB)(e[i].x[1]-e[j].x[0])/(DB)(e[j].y-e[i].y)<<endl;
			p.push_back({(DB)(e[i].x[0]-e[j].x[1])/(DB)(e[j].y-e[i].y),2});
			p.push_back({(DB)(e[i].x[1]-e[j].x[0])/(DB)(e[j].y-e[i].y),1});
		}
	}
	sort(p.begin(),p.end());
	cnt=0;
	for(int i=0;i<p.size();++i) {
		if(p[i].second==2){
			if(!cnt) p2.push_back(p[i].first);
			++cnt;
		}
		else{
			--cnt;
			if(!cnt) p2.push_back(p[i].first);
		}
	}
	if(!p2.size()) p2.push_back(0);
	//for(int i=0;i<p2.size();++i) cout<<p2[i]<<endl;
	int now=m+1;
	for(int i=0;i<p2.size();++i){
		while((DB)a[now].y*p2[i]+(DB)a[now].x>=(DB)a[now-1].y*p2[i]+(DB)a[now-1].x&&now>1) --now;
		mn.push_back((DB)a[now].y*p2[i]+(DB)a[now].x);
	}
	for(int i=1;i<=m;++i){
		if(a[i].x==rd.x&&a[i].y==rd.y){
			swap(a[i],a[1]);
			break;
		}
	}
	sort(a+2,a+m+1,cmpa);
	a[m+1]=a[1];
	//for(int i=1;i<=m;++i) cout<<a[i].x<<" "<<a[i].y<<endl;
	now=m+1;
	for(int i=0;i<p2.size();++i){
		while((DB)a[now].y*p2[i]+(DB)a[now].x<=(DB)a[now-1].y*p2[i]+(DB)a[now-1].x&&now>1) --now;
		mx.push_back((DB)a[now].y*p2[i]+(DB)a[now].x);
	}
	DB ans=mx[0]-mn[0];
	for(int i=0;i<p2.size();++i){
		if(mx[i]-mn[i]<ans) ans=mx[i]-mn[i];
	}
	printf("%0.8Lf\n",ans);
	return 0;
}
/*
4
1 5 4
1 4 3
1 6 2
1 5 1

*/