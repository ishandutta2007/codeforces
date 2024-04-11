#include <bits/stdc++.h>
#define M (1<<20)
using namespace std;

int d[M],p[M];

int main(){
	int n,k;
	memset(p,-1,sizeof(p));
	for(int i=2;i<M;++i)if(p[i]<0)for(int j=i;j<M;j+=i)p[j]=i;
	scanf("%d%d",&n,&k);
	memset(d,0,sizeof(d));
	while(k>1)d[p[k]]++,k/=p[k];
	while(n--){
		int c;scanf("%d",&c);
		while(c>1){
			int w=p[c],j=0;
			while(p[c]==w){
				c/=w;
				j++;
			}
			if(j>=d[w])d[w]=0;
		}
	}
	bool r=true;
	for(int i=2;i<M;++i)r=r&&d[i]==0;
	puts(r?"Yes":"No");
	return 0;
}