#include <bits/stdc++.h>
#define maxn 200005
#define maxb 800
const int ouuan=998244353;
int n,k,i,size,b[maxn],arr[maxn],dp[maxn]={0},belong[maxn],q[maxb][maxb],pre[maxn],cnt[maxn]={0},sum[maxn]={0};
std::vector<int>appear[maxn];
void rebuild(int p) {
	sum[p]=0;
	int l=(p-1)*size+1,r=p*size;
	std::memset(q[p],0,sizeof(q[p]));
	for (int i=r;i>=l;--i) {
		sum[p]+=b[i];
		q[p][size+sum[p]]=(q[p][size+sum[p]]+dp[i-1])%ouuan;
	}for (int i=-size+1;i<=size;++i) q[p][size+i]=(q[p][size+i]+q[p][size+i-1])%ouuan;
}

void modify(int p,int v) {
	b[p]=v;
	//if (belong[p]==belong[i]) return;
	rebuild(belong[p]);
}

int query(int p,int w) {
//	printf("query:%d under %d\n",p,w);
	if (w<-size) return 0;
//	for (int i=-size;i<=size;++i) printf("%d ",q[p][size+i]);
//	printf("ans=%d\n",q[p][std::min(w,size)]);
	return q[p][size+std::min(w,size)];
}


int main() {
	dp[0]=1; //freopen("sample.txt","r",stdin);
	scanf("%d%d",&n,&k);
	size=(int)std::sqrt(n);
	for (int i=1;i<=n;++i) {
		belong[i]=(i-1)/size+1;
		scanf("%d",&arr[i]);
		appear[arr[i]].push_back(i);
	} 
	for (int i=1;i<=n;++i) {
		for (int j=0;j<appear[i].size();++j) {
			if (j==0) pre[appear[i][j]]=0;
			else pre[appear[i][j]]=appear[i][j-1];
		}
	}for (int i=1;i<=n;++i) cnt[i]=cnt[pre[i]]+1;
//for (int i=1;i<=n;++i) printf("%d ",pre[i]); printf("\n");
//	for (int i=1;i<=n;++i) printf("%d ",cnt[i]); printf("\n");
	for (i=1;i<=n;++i) {
		int tot=0;
		if (cnt[i]>=3) modify(pre[pre[i]],0);
		if (cnt[i]>=2) modify(pre[i],-1);
		modify(i,1);
		for (int j=i;belong[j]==belong[i];j--) 
			{tot+=b[j];if (tot<=k) dp[i]=(dp[i]+dp[j-1])%ouuan;}
		for (int j=belong[i]-1;j>=1;j--) {
			dp[i]=(dp[i]+query(j,k-tot))%ouuan;
			//b(i~r)+tot<=k i.e b(i~r)<=k-tot
			tot+=sum[j];
		}//for (int j=1;j<=i;++j) printf("%d ",b[j]);
		//printf("%d ",dp[i]);printf("<\n");
	}printf("%d",dp[n]);	
	return 0;
}