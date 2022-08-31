#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

int x[3],go[3],jump[3],bear[3],get[3];
int ans;

const int MOD=1000000007;

bitset<MOD> F;

int hash(int s)
{
	for (int i=0;i<3;++i)
		s=(s*10007+x[i]*101+bear[i]*97+get[i]*61)%MOD;
	if (s<0) s+=MOD;
	return s;
}

void DFS(int s)
{
	ans=max(ans,max(x[0],max(x[1],x[2])));
	if (ans==42) return;
	if (!s) return;
	int h=hash(s);
	if (F[h]) return;
	F[h]=1;
	for (int k=0;k<3;++k)
	{
		int p=3*k;
		if ((s&(1<<p))&&!get[k]&&bear[k]==-1)
			for (int i=max(1,x[k]-go[k]);i<=x[k]+go[k];++i)
			{
				if (x[0]==i||x[1]==i||x[2]==i) continue;
				int tx=x[k];
				x[k]=i;
				DFS(s^(1<<p));
				x[k]=tx;
			}
		if ((s&(2<<p))&&!get[k]&&bear[k]==-1)
			for (int i=0;i<3;++i) if (!get[i]) if (x[i]-x[k]==1||x[i]-x[k]==-1)
			{
				int tx=x[i];
				x[i]=x[k];
				get[i]=1;
				bear[k]=i;
				if (bear[i]!=-1) x[bear[i]]=x[k];
				DFS(s^(2<<p));
				x[i]=tx;
				get[i]=0;
				bear[k]=-1;
				if (bear[i]!=-1) x[bear[i]]=tx;
			}
		if ((s&(4<<p))&&!get[k]&&bear[k]!=-1)
			for (int i=max(1,x[k]-jump[k]);i<=x[k]+jump[k];++i)
			{
				if (x[0]==i||x[1]==i||x[2]==i) continue;
				int tb=bear[k];
				int tx=x[tb];
				x[tb]=i;
				bear[k]=-1;
				get[tb]=0;
				if (bear[tb]!=-1) x[bear[tb]]=i;
				DFS(s^(4<<p));
				x[tb]=tx;
				bear[k]=tb;
				get[tb]=1;
				if (bear[tb]!=-1) x[bear[tb]]=tx;
			}
	}
}

int main()
{
	for (int i=0;i<3;++i)
	{
		cin>>x[i]>>go[i]>>jump[i];
		bear[i]=-1;
	}
	DFS(511);
	cout<<ans<<endl;
	return 0;
}