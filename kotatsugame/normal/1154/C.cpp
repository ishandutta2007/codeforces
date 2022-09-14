#include<cstdio>
#include<algorithm>
using namespace std;
int calc(int A,int B,int C)
{
	if(A<0||B<0||C<0)return -1e9;
	int T=min(A/3,min(B/2,C/2));
	A-=T*3;
	B-=T*2;
	C-=T*2;
	int ret=T*7;
	if(A==0)return ret;
	else A--,ret++;
	if(B==0)return ret;
	else B--,ret++;
	if(C==0)return ret;
	else C--,ret++;
	if(A==0)return ret;
	else A--,ret++;
	if(C==0)return ret;
	else C--,ret++;
	if(B==0)return ret;
	else B--,ret++;
	return ret;
}
int t[]={0,1,2,0,2,1,0};
main()
{
	int A[3];
	scanf("%d%d%d",&A[0],&A[1],&A[2]);
	int ans=0;
	for(int i=0;i<7;i++)
	{
		int a[3];
		for(int j=0;j<3;j++)a[j]=A[j];
		bool out=false;
		for(int k=i;k<7;k++)
		{
			if(a[t[k]]>0)a[t[k]]--;
			else
			{
				out=true;
				break;
			}
			ans=max(ans,k-i+1);
		}
		if(!out)ans=max(ans,7-i+calc(a[0],a[1],a[2]));
	}
	printf("%d\n",ans);
}