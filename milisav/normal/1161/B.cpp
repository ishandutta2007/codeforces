#include<bits/stdc++.h>
using namespace std;
vector<int> s[300000];
vector<int> divs;
bool p[300000];
int n,m;
int nzs(int a,int b) {
	long long x=a,y=b;
	long long z=__gcd(a,b);
	return x*y/z;
}
bool check(int id,int t) {
	bool rt=true;
	for(int i=0;i<s[id].size();i++) p[s[id][i]]=true;
	for(int i=0;i<s[id].size();i++) {
		int j=s[id][i]+t;
		if(j>n) j-=n;
		if(!p[j]) {
			rt=false;
			break;
		}
	}
	for(int i=0;i<s[id].size();i++) p[s[id][i]]=false;
	return rt;
}
int main()
{
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		if(b<a) swap(a,b);
		int p=a;
		int t=abs(a-b);
		if(2*abs(a-b)>n) {
			p=b;
			t=n-abs(a-b);
		}
		if(t*2==n) {
			s[t].push_back(a);
			s[t].push_back(b);
		}
		else s[t].push_back(p);
	}
	for(int i=1;i<=n;i++) {
		if(n%i==0) divs.push_back(i);
	}
	//if(check(1,3)) printf("OK");
	int tp=1;
	for(int i=1;i<=n && tp!=n;i++) {
		if(s[i].size()==0) continue;
		int gp;
		if(i*2==n) {
			sort(s[i].begin(),s[i].end());
			if(s[i].size()==1) tp=n;
			else {
				for(int j=0;j<divs.size();j++) {
					if(check(i,divs[j])) {
						gp=divs[j];
						break;
					}
				}
				if(tp<n) tp=min(nzs(tp,gp),nzs(tp,n/2));
			}
		}
		else {
			sort(s[i].begin(),s[i].end());
			if(s[i].size()==1) tp=n;
			else {
				for(int j=0;j<divs.size();j++) {
					if(check(i,divs[j])) {
						gp=divs[j];
						break;
					}
				}
				if(tp<n) tp=nzs(tp,gp);
			}
		}
	}
	if(tp<n) printf("Yes");
	else printf("No");
	return 0;
}