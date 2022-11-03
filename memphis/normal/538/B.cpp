#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//#include<set>
//#include<map>
#include<queue>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define rev(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
using namespace std;
#define N 1000005
#define LL long long
#define inf 0x3f3f3f3f

int n,a[N],f[N],from[N];

void dfs(int x){
	if(x>1000000) return;
	a[++*a]=x;
	dfs(x*10);
	dfs(x*10+1);
}

int main(){
	dfs(1);
	n=N-5;
	//printf("%d\n",*a);
	sort(a+1,a+1+*a);
	rep(i,1,n){
		f[i]=inf;
		rep(j,1,*a){
			if(a[j]>i) break;
			if(f[i-a[j]]+1<f[i]){
				f[i]=f[i-a[j]]+1;
				from[i]=i-a[j];
			}
		}
	}
	scanf("%d",&n);
	printf("%d\n",f[n]);
	while(n){
		printf("%d ",n-from[n]);
		n=from[n];
	}
}