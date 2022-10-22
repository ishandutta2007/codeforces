#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
int m,n,t;
vector<int>af,az,bf,bz,c;
inline int calc(vector<int>a,vector<int>b){
	if(!a.size()||!b.size())return 0;
	c.clear();
	c.resize(a.size()+1);
	for(ri i=a.size()-1;i>=0;--i){
		int tmp=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		c[i]=c[i+1];
		if(i<a.size()&&tmp<b.size()&&a[i]==b[tmp])++c[i];
	}
	ri ret=c[0];
	for(ri i=1,j=0;j<b.size();++j){
		if(b[j]<a[0])continue;
		while(i<a.size()&&a[i]<=b[j]+i-1)++i;
		ri tmp=upper_bound(b.begin(),b.end(),b[j]+i-1)-b.begin()-j+c[i];
		ret=max(ret,tmp);
	}
	return ret;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		af.clear(),az.clear(),bf.clear(),bz.clear();
		for(ri i=1;i<=n;++i){
			int a;
			scanf("%d",&a);
			if(a<0)af.push_back(-a);
			if(a>0)az.push_back(a);
		}
		reverse(af.begin(),af.end());
		for(ri i=1;i<=m;++i){
			int b;
			scanf("%d",&b);
			if(b<0)bf.push_back(-b);
			if(b>0)bz.push_back(b);
		}
		reverse(bf.begin(),bf.end());
		printf("%d\n",calc(af,bf)+calc(az,bz));
	}
	return 0;
}