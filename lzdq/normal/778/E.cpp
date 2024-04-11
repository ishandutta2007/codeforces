#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1005;
int n,m,len[MAXN],c[10],rg[MAXN][2];
char a[MAXN],b[MAXN][MAXN],_[MAXN];
int p[MAXN],q[MAXN],rk[MAXN];
int f[MAXN][MAXN];
int w[10],cnt[10];
queue<int> que[10];
int sum,ans;
int main(){
	//freopen("in","r",stdin);
	scanf("%s",_+1);
	m=strlen(_+1);
	for(int i=1; i<=m; i++){
		a[i]=_[m-i+1];
		if(a[i]=='?') rg[i][0]=0,rg[i][1]=9;
		else rg[i][0]=rg[i][1]=a[i]-'0';
	}
	rg[m][0]=max(rg[m][0],1);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%s",_+1);
		len[i]=strlen(_+1);
		for(int j=1; j<=len[i]; j++)
			b[i][j]=_[len[i]-j+1]-'0';
		p[i]=i;
	}
	for(int i=0; i<10; i++)
		scanf("%d",c+i);
	memset(f,0xc0,sizeof(f));
	f[1][0]=0;
	for(int i=1; i<=m; i++){
		//printf("i %d\n",i); for(int j=1; j<=n; j++) printf("%d ",p[j]); puts("");
		for(int j=1; j<=n; j++)
			que[b[p[j]][i]].push(p[j]);
		*q=0;
		for(int j=9; ~j; j--)
			while(!que[j].empty())
				q[++*q]=que[j].front(),que[j].pop();
		for(int j=1; j<=n; j++)
			rk[q[j]]=j;
		for(int k=0; k<10; k++){
			w[k]=cnt[k]=0;
			for(int j=1; j<=n; j++){
				cnt[k]+=c[(b[q[j]][i]+k)%10];
				if(b[q[j]][i]+k>=10) w[k]=j;
			}
		}
		for(int j=0; j<=n; j++){
			if(j) for(int k=0; k<10; k++){
				if(k+b[p[j]][i]+1>=10) w[k]=max(w[k],rk[p[j]]);
				cnt[k]=cnt[k]-c[(b[p[j]][i]+k)%10]+c[(b[p[j]][i]+k+1)%10];
			}
			if(f[i][j]>=0) for(int k=rg[i][0]; k<=rg[i][1]; k++)
				f[i+1][w[k]]=max(f[i+1][w[k]],f[i][j]+cnt[k]);
		}
		for(int j=1; j<=n; j++)
			p[j]=q[j];
	}
	for(int i=1; i<=n; i++)
		for(int j=m+1; j<=len[i]; j++)
			sum+=c[b[i][j]];
	for(int i=0; i<=n; i++){
		if(i){
			int t=m+1;
			while(b[p[i]][t]==9) sum=sum-c[9]+c[0],t++;
			if(t<=len[p[i]]) sum-=c[b[p[i]][t]];
			sum+=c[b[p[i]][t]+1];
		}
		ans=max(ans,f[m+1][i]+sum);
	}
	printf("%d\n",ans);
	return 0;
}