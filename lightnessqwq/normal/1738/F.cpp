#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,T,tot;
int a[maxn],c[maxn],id[maxn];
inline int cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),id[i]=i;
		sort(id+1,id+1+n,cmp);
		for(int i=1;i<=n;i++){
			int x=id[i];
			if(c[x]==0){
				vector<int>v;
				for(int j=1,y;j<=a[x];j++){
					printf("? %d\n",x),fflush(stdout);
					scanf("%d",&y);
					if(c[y]==0)
						v.push_back(y);
					else{
						c[x]=c[y];
						break;
					}
				}
				if(c[x]==0)
					c[x]=++tot;
				while(v.size())
					c[v.back()]=c[x],v.pop_back();
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d%c",c[i],i==n? '\n':' '),c[i]=0;
		fflush(stdout);
	}
	return 0;
}