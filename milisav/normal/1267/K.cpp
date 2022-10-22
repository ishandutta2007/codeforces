#include <bits/stdc++.h>
using namespace std;
long long b[100][100];
int cnt[50];
int main()
{
	for(int i=0;i<100;i++) b[i][0]=1;
	for(int i=1;i<100;i++) for(int j=1;j<=i;j++) b[i][j]=b[i-1][j]+b[i-1][j-1];
	int t; cin>>t;
	while(t--)
	{
		long long k,rs1=1,rs2=1;
		cin>>k;
		int br=2,pr=0;
		fill(cnt,cnt+50,0);
		for(br=2;k;br++)
		{
			cnt[k%br]++;
			k/=br;
		}
		br-=2;
		bool mn=cnt[0]>0;
		for(int i=br;i>0;i--)
		{
			rs1*=b[br-i-pr+1][cnt[i]];
			if(mn) rs2*=b[br-i-pr][cnt[i]];
			pr+=cnt[i];
		}
		long long res=rs1-1;
		if(mn) res-=rs2;
		cout<<res<<endl;
	}
}