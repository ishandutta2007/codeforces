#include <bits/stdc++.h>
using namespace std;

int p[2048],v[2048];
int n;

int r;
vector<pair<int,int> > sol;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",p+i);
	}
	for(int i=0;i<n;++i){
		int k;
		scanf("%d",&k);
		v[k]=i;
	}
	for(int i=0;i<n;++i){
		p[i]=v[p[i]];
	}
	//for(int i=0;i<n;++i)printf("%d ",p[i]);
	for(int i=0;i<n;++i){
		int j;
		for(j=i;;++j)if(p[j]==i)break;
		while(j!=i){
			int k=j-1;
			while(p[k]<j)k--;//printf("\n%d %d  %d %d\n",j,p[j],k,p[k]);
			swap(p[j],p[k]);
			sol.push_back(make_pair(j,k));
			r+=j-k;
			j=k;
		}
	}
	printf("%d\n%d\n",r,(int)sol.size());
	for(int i=0;i<sol.size();++i)printf("%d %d\n",sol[i].first+1,sol[i].second+1);
	return 0;
}