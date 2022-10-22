#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,L[N],R[N],zL[17][N],zR[17][N];ll ans,wL[17][N],wR[17][N];
int bL[N][26],bR[N][26],psL[N][26],psR[N][26];char a[N];
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=0;i<26;++i) psL[0][i]=1,psR[n+1][i]=n;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j) psL[i][j]=psL[i-1][j];psL[i][a[i]-'a']=i;
		for(int j=0;j<26;++j) bL[i][j]=psL[i][j];sort(bL[i],bL[i]+26);
		reverse(bL[i],bL[i]+26);
	}
	for(int i=n;i;--i)
	{
		for(int j=0;j<26;++j) psR[i][j]=psR[i+1][j];psR[i][a[i]-'a']=i;
		for(int j=0;j<26;++j) bR[i][j]=psR[i][j];sort(bR[i],bR[i]+26);
	}for(int i=1;i<=n;++i) L[i]=R[i]=i,zL[0][i]=n+1;
	for(int i=0,tL,tR;i<26;++i)
	{
		for(int j=1;j<=n;++j)
		{
			zL[0][j]=min(zL[0][j],psL[j-1][a[bR[j][i]]-'a']);
			zR[0][j]=max(zR[0][j],psR[j+1][a[bL[j][i]]-'a']);
			wL[0][j]=j-1;wR[0][j]=n-j;
		}
		for(int j=1;j<=16;++j) for(int k=1;k<=n;++k)
		{
			zL[j][k]=zL[j-1][zL[j-1][k]];zR[j][k]=zR[j-1][zR[j-1][k]];
			wL[j][k]=wL[j-1][k]+wL[j-1][zL[j-1][k]];
			wR[j][k]=wR[j-1][k]+wR[j-1][zR[j-1][k]];
		}
		for(int j=1;j<=n;++j)
		{
			for(int k=16;k>=0;--k)
			{
				tL=zL[k][L[j]];tR=zR[k][R[j]];
				if(i==25 || (tL>1 && tR<n && bL[tR][i+1]<tL))
					ans+=wL[k][L[j]]+wR[k][R[j]],L[j]=tL,R[j]=tR;
			}tL=zL[0][L[j]];tR=zR[0][R[j]];
			if(L[j]>1 && R[j]<n && bL[R[j]][i+1]<L[j])
				ans+=wL[0][L[j]]+wR[0][R[j]],L[j]=tL,R[j]=tR;
		}
	}printf("%lld\n",ans);return 0;
}