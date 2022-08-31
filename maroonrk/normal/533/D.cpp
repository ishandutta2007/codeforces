#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

typedef pair<int,int> pii;
int cs[100001];

vector<pii> Clac(const vector<int>& x,const vector<int>& d){
	int n=x.size();
	vector<pii> ret(n);
	ret[0]=MP(x[0],d[0]);
	int k=0;
	cs[k++]=0;
	FOR(i,1,n){
		cs[k++]=i;
		while(k>=2){
			if(x[cs[k-1]]-x[cs[k-2]]>=d[cs[k-1]])
				k--;
			else if(k>=3&&x[cs[k-1]]-x[cs[k-3]]>d[cs[k-2]]){
				cs[k-2]=cs[k-1];
				k--;
			}else
				break;
		}
		if(k==1)
			ret[i]=MP(x[0],d[0]);
		else
			ret[i]=MP(x[cs[k-1]],d[cs[k-1]]+x[cs[k-2]]);
	}
	return ret;
}

int xBuf[100002],dBuf[100002];

typedef pair<pii,pii> ppp;
ppp qs[400004];

int main(){
	int n=read();
	REP(i,n+2)
		xBuf[i]=read();
	REP(i,n)
		dBuf[i]=read()*2;
	vector<int> x1(n+1),x2(n+1),d1(n+1),d2(n+1);
	REP(i,n+1)
		x1[i]=xBuf[i];
	d1[0]=INT_MAX;
	REP(i,n)
		d1[i+1]=dBuf[i];
	REP(i,n+1)
		x2[i]=xBuf[n+1]-xBuf[n+1-i];
	d2[0]=INT_MAX;
	REP(i,n)
		d2[i+1]=dBuf[n-1-i];
	vector<pii> r1=Clac(x1,d1);
	if(r1[n].first!=0&&xBuf[n+1]<=r1[n].second){
		printf("0\n");
		return 0;
	}
	int k=0;
	for(auto p:r1){
		qs[k++]=MP(MP(p.first,-1),MP(1,p.first));
		qs[k++]=MP(MP(p.second,-1),MP(2,p.first));
	}
	vector<pii> r2=Clac(x2,d2);
	for(auto p:r2){
		qs[k++]=MP(MP(xBuf[n+1]-p.second,-2),MP(1,xBuf[n+1]-p.first));
		qs[k++]=MP(MP(xBuf[n+1]-p.first,-2),MP(2,xBuf[n+1]-p.first));
	}
	sort(qs,qs+k);
	int ans=INT_MAX;
	multiset<int> s1,s2;
	REP(i,k){
		//int x=qs[i].first.first;
		int type=-qs[i].first.second;
		int ad=qs[i].second.first;
		int v=qs[i].second.second;
		if(ad==1){
			if(type==1)
				s1.insert(v);
			else
				s2.insert(v);
			if(!s1.empty()&&!s2.empty()){
				int u=*(--s1.end());
				int t=*s2.begin();
				ans=min(ans,t-u);
			}
		}else{
			if(type==1)
				s1.erase(v);
			else
				s2.erase(v);
		}
	}
	printf("%.10f\n",(double)ans/2);
}