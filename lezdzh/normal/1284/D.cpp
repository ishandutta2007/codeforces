#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int l1[100001],r1[100001],l2[100001],r2[100001];
int z[400001];
vector<int>g1[400001],g2[400001];
int c[1100001],h;
int cx(int p){
	int ans=-2e9;
	for(p=p+h+1;p>1;p>>=1)
		if(p&1)ans=max(ans,c[p-1]);
	return ans;
}
void xg(int p,int cc){
	p+=h;
	c[p]=cc;
	for(p>>=1;p;p>>=1)
		c[p]=max(c[p<<1],c[p<<1|1]);
}
bool check(){
	for(h=1;h<=z[0];h<<=1);
	for(int i=0;i<=h+z[0]+1;i++)
		c[i]=-2e9;
	for(int i=1;i<=z[0];i++){
		for(int j=0;j<g2[i].size();j++)
			if(cx(r2[g2[i][j]])>=l2[g2[i][j]])
				return 0;
		for(int j=0;j<g1[i].size();j++)
			xg(l2[g1[i][j]],r2[g1[i][j]]);
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&l1[i],&r1[i],&l2[i],&r2[i]);
		z[++z[0]]=l1[i];
		z[++z[0]]=r1[i];
		z[++z[0]]=l2[i];
		z[++z[0]]=r2[i];
	}
	sort(z+1,z+z[0]+1);
	z[0]=unique(z+1,z+z[0]+1)-z-1;
	for(int i=1;i<=n;i++){
		l1[i]=lower_bound(z+1,z+z[0]+1,l1[i])-z;
		r1[i]=lower_bound(z+1,z+z[0]+1,r1[i])-z;
		l2[i]=lower_bound(z+1,z+z[0]+1,l2[i])-z;
		r2[i]=lower_bound(z+1,z+z[0]+1,r2[i])-z;
	}
	for(int i=1;i<=n;i++){
		g2[l1[i]].push_back(i);
		g1[r1[i]].push_back(i);
	}
	if(!check()){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=z[0];i++){
		g1[i].clear();
		g2[i].clear();
	}
	for(int i=1;i<=n;i++){
		swap(l1[i],l2[i]);
		swap(r1[i],r2[i]);
	}
	for(int i=1;i<=n;i++){
		g2[l1[i]].push_back(i);
		g1[r1[i]].push_back(i);
	}
	if(!check()){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
}