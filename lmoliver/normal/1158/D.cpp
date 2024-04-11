#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y):x(_x),y(_y){}
	inline void read(){
		scanf("%d%d",&x,&y);
	}
	double to(const P o)const{
		// cerr<<"("<<o.x-x<<","<<o.y-y<<")"<<endl;
		return atan2(o.y-y,o.x-x);
	}
	inline P operator-(const P o)const{
		return P(x-o.x,y-o.y);
	}
	bool left(const P a,const P b)const{
		P x=a-*this;
		P y=b-*this;
		return (LL)x.x*y.y-(LL)x.y*y.x>0;
	}
};
const int N=2020;
const double PI=acos(-1);
P p[N];
bool del[N]={false};
char s[N];
int ans[N];
int main(){
	// cerr<<atan2(1,1)
	int n;
	scanf("%d",&n);
	int mr=1;
	for(int i=1;i<=n;i++){
		p[i].read();
		if(p[i].x>p[mr].x)mr=i;
	}
	scanf("%s",s);
	ans[1]=mr;
	del[ans[1]]=true;
	int last=ans[1];
	for(int i=2;i<=n;i++){
		if(i==n){
			for(int j=1;j<=n;j++){
				if(!del[j]){
					ans[i]=j;
					del[ans[i]]=true;
					break;
				}
			}
			continue;
		}
		int lb=0;
		int rb=0;
		const P &pl=p[last];
		// cerr<<i<<" last="<<last<<endl;
		for(int j=1;j<=n;j++){
			if(del[j])continue;
			// double tans=pl.to(p[j]);
			// cerr<<j<<":"<<tans<<endl;
			if(!lb||pl.left(p[lb],p[j]))lb=j;
			if(!rb||!pl.left(p[rb],p[j]))rb=j;
		}
		// cerr<<"lb="<<lb<<" rb="<<rb<<endl;
		last=ans[i]=s[i-2]=='L'?rb:lb;
		del[ans[i]]=true;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}