#include<iostream>
using namespace std;
long long cnt[120][120];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q;cin>>Q;
	for(;Q--;)
	{
		long long t;
		int gx,gy;
		cin>>t>>gx>>gy;
		t-=gx+gy;
		if(t<0)
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<=gx;i++)for(int j=0;j<=gy;j++)cnt[i][j]=0;
		cnt[0][0]=t;
		for(int i=0;i<=gx;i++)for(int j=0;j<=gy;j++)
		{
			if(j+1<=gy)cnt[i][j+1]+=(cnt[i][j]+1)/2;
			if(i+1<=gx)cnt[i+1][j]+=cnt[i][j]/2;
		}
		int x=0,y=0;
		for(int i=0;x<=gx&&y<=gy&&i<gx+gy;i++)
		{
			if(cnt[x][y]%2==0)y++;
			else x++;
		}
		cout<<(x==gx&&y==gy?"YES\n":"NO\n");
	}
}