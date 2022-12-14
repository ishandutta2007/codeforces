#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long cclan[22][444444],clan[22][444444],an[22][444444],ann[22][444444],wei[444444],q,lst,x,y,tp,cnt,xx,ans;
int main()
{
	scanf("%I64d",&q);
	cnt=1;
	while(q--)
	{
		scanf("%I64d%I64d%I64d",&tp,&x,&y);
		x^=lst;y^=lst;
		if (tp==1)
		{
			cnt++;
			wei[cnt]=y;
			xx=x;
			for (long long i=20;i>=0;i--)
			{
				if (an[i][xx]<y) xx=cclan[i][xx];
			}
			clan[0][cnt]=xx;cclan[0][cnt]=x;
			an[0][cnt]=ann[0][cnt]=y;
			for (long long i=1;i<=20;i++)
			{
				cclan[i][cnt]=cclan[i-1][cclan[i-1][cnt]];
				clan[i][cnt]=clan[i-1][clan[i-1][cnt]];
				an[i][cnt]=max(an[i-1][cnt],an[i-1][cclan[i-1][cnt]]);
				ann[i][cnt]=ann[i-1][cnt]+ann[i-1][clan[i-1][cnt]];
			}
		}
		else
		{
			ans=0;
			for (long long i=20;i>=0;i--)
			{
				if (!clan[i][x]) continue;
				if (ann[i][x]>y) continue;
				ans+=pow(2,i);
				y-=ann[i][x];
				x=clan[i][x];
			}
			if (wei[x]<=y) ans++;
			printf("%I64d\n",ans);
			lst=ans;
		}
	}
	return 0;
}