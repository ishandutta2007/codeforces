#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=2e5+5,INF=0x7fffffff;
typedef pair<int,int> pr;
#define mkp make_pair
int n,m,k,a[MAXN];
int sum[2][2][MAXN],cnt[2][2];
pr c[2][2][MAXN];
int ans,s,sol;
set<pr> s1,s2,s3,s4;
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++){
		int x,y;
		scanf("%d%d%d",a+i,&x,&y);
		c[x][y][++cnt[x][y]]=mkp(a[i],i);
	}
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			sort(c[i][j]+1,c[i][j]+cnt[i][j]+1);
			for(int k=1; k<=cnt[i][j]; k++)
				sum[i][j][k]=sum[i][j][k-1]+c[i][j][k].first;
		}
	for(int i=1; i<=cnt[0][0]; i++)
		s2.insert(c[0][0][i]);
	for(int i=k+1; i<=cnt[0][1]; i++)
		s2.insert(c[0][1][i]);
	for(int i=k+1; i<=cnt[1][0]; i++)
		s2.insert(c[1][0][i]);
	ans=INF;
	for(int i=0; i<=cnt[1][1]; i++){
		int y=max(0,k-i);
		if(y<=min(cnt[0][1],cnt[1][0])&&m-i-y*2>=0&&m-i-y*2<=s1.size()+s2.size()){
			int k=m-i-y*2;
			while(s1.size()<k){
				auto it=s2.begin();
				s1.insert(*it);
				s+=it->first;
				s2.erase(it);
			}
			while(s1.size()>k){
				auto it=s1.end();
				it--;
				s2.insert(*it);
				s-=it->first;
				s1.erase(it);
			}
			if(!s1.empty()&&!s2.empty())
				while(1){
					auto i1=s1.end();
					i1--;
					auto i2=s2.begin();
					if(*i1>*i2){
						s=s-i1->first+i2->first;
						pr t=*i2;
						s2.insert(*i1);
						s2.erase(t);
						s1.erase(i1);
						s1.insert(t);
					}else break;
				}
			int res=sum[1][1][i]+sum[0][1][y]+sum[1][0][y]+s;
			if(ans>res) ans=res;
		}
		if(k>i){
			if(y<=cnt[0][1]) s2.insert(c[0][1][y]);
			if(y<=cnt[1][0]) s2.insert(c[1][0][y]);
		}
	}
	if(ans==INF) return puts("-1"),0;
	printf("%d\n",ans);
	s1.clear();
	s2.clear();
	s=0;
	for(int i=1; i<=cnt[0][0]; i++)
		s2.insert(c[0][0][i]);
	for(int i=k+1; i<=cnt[0][1]; i++)
		s2.insert(c[0][1][i]);
	for(int i=k+1; i<=cnt[1][0]; i++)
		s2.insert(c[1][0][i]);
	for(int i=0; i<=cnt[1][1]; i++){
		int y=max(0,k-i);
		if(y<=min(cnt[0][1],cnt[1][0])&&m-i-y*2>=0&&m-i-y*2<=s1.size()+s2.size()){
			int k=m-i-y*2;
			while(s1.size()<k){
				auto it=s2.begin();
				s1.insert(*it);
				s+=it->first;
				s2.erase(it);
			}
			while(s1.size()>k){
				auto it=s1.end();
				it--;
				s2.insert(*it);
				s-=it->first;
				s1.erase(it);
			}
			if(!s1.empty()&&!s2.empty())
				while(1){
					auto i1=s1.end();
					i1--;
					auto i2=s2.begin();
					if(*i1>*i2){
						s=s-i1->first+i2->first;
						pr t=*i2;
						s2.insert(*i1);
						s2.erase(t);
						s1.erase(i1);
						s1.insert(t);
					}else break;
				}
			int res=sum[1][1][i]+sum[0][1][y]+sum[1][0][y]+s;
			if(ans==res){
				sol=i;
				break;
			}
		}
		if(k>i){
			if(y<=cnt[0][1]) s2.insert(c[0][1][y]);
			if(y<=cnt[1][0]) s2.insert(c[1][0][y]);
		}
	}
	int x=sol,y=max(0,k-x);
	for(int i=1; i<=x; i++)
		printf("%d ",c[1][1][i].second);
	for(int i=1; i<=y; i++)
		printf("%d %d ",c[0][1][i].second,c[1][0][i].second);
	for(auto it=s1.begin(); it!=s1.end(); it++)
		printf("%d ",it->second);
	puts("");
	return 0;
}