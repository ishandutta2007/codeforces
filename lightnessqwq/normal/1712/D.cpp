#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg,mx,mxx;
int a[maxn],vis[maxn],b[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int L=0,R=1000000001;
		while(L+1<R){
			int mid=(L+R)>>1,tot=0;
			mx=mxx=0;
			for(int i=1;i<=n;i++){
				if(a[i]*2<mid)
					tot++,b[i]=1e9;
				else b[i]=a[i];
				mxx=max(mxx,b[i]);
			}
			for(int i=1;i<n;i++)
				mx=max(mx,min(b[i],b[i+1]));
			if(mx<mid&&mxx>=mid)
				tot++;
			if(mx<mid&&mxx<mid)
				tot+=2;
			if(tot<=m)
				L=mid;
			else R=mid;
		}
		printf("%d\n",L);
	}
	return 0;
}