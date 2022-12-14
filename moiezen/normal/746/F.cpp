#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define pi std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second
#define N 400005
int n,m,k,c[N],w[N],top[N],ans;
std::priority_queue<pi> m1,m2;
int current,last,result,size;pi xx;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rpt(i,1,n) scanf("%d",&w[i]);
	rpt(i,1,n) scanf("%d",&c[i]);
	last=n;current=result=size=0;
	rpd(i,n,1){
		if(!m1.empty()){
			xx=m1.top();
			while(xx.se>last) m1.pop(),xx=m1.top();
		}
		else xx=mp(0,0);
		if(size<m) m1.push(mp(-c[i],i)),current+=(c[i]+1)/2,size++,top[i]=1;
		else{
			if(-xx.fi<c[i]){
				m1.pop();current+=c[xx.se];current-=(c[xx.se]+1)/2;top[xx.se]=0;
				m2.push(mp(c[xx.se],xx.se));
				m1.push(mp(-c[i],i));current+=(c[i]+1)/2;top[i]=1;
			}
			else{
				m2.push(mp(c[i],i));
				current+=c[i];
			}
		}
		result+=w[i];
		while(current>k){
			if(top[last]==1) current-=(c[last]+1)/(top[last]+1);
			else current-=c[last];
			if(top[last]){
				size--;
				if(!m2.empty()){
					xx=m2.top();
					while(xx.se>=last&&!m2.empty()){
						m2.pop();
						if(!m2.empty()) xx=m2.top();
					}
					if(!m2.empty()){
						m2.pop();
						m1.push(mp(-xx.fi,xx.se));
						current-=(xx.fi)/2;top[xx.se]=1;size++;
					}
				}
			}
			result-=w[last--];
		}
		ans=std::max(ans,result);
	}
	printf("%d\n",ans);
}