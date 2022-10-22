#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn],b[maxn],deg[maxn],q[maxn];
vector<int>v[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=flg=0;
		scanf("%d",&n);
		int k=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>i)
				k=i;
			if(a[i]!=0&&a[i]!=n+1)
				v[a[i]].push_back(i);
		}
		int hd=1,tl=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0||a[i]==n+1)
				q[++tl]=i;
		int bs=0;
		while(hd<=tl){
			int now=hd;
			while(now+1<=tl&&(q[now+1]<=k)==(q[now]<=k))
				now++;
			for(int i=hd;i<=now;i++)
				if(v[q[i]].size()==0)
					b[++bs]=q[i];
			for(int i=hd;i<=now;i++)
				if(v[q[i]].size()){
					int x=q[i];
					b[++bs]=x;
					for(int j=0;j<v[x].size();j++)
						q[++tl]=v[x][j];
				}
			hd=now+1;
		}
		printf("%d\n",k);
		for(int i=1;i<=n;i++)
			printf("%d%c",b[i],i==n? '\n':' ');
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}