#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[20][5][2];
int r[20];
inline int calc(int R)
{
	if(R==0)
		return 1;
	int i,j,k,len,c;
	for(i=1;R;i++)
		r[i]=R%10,R/=10,len=i;
	reverse(r+1,r+len+1);
	memset(f,0,sizeof(f));
	for(j=0;j<=3;j++)
		for(k=0;k<2;k++)
			f[len][j][k]=1;//base case
	for(i=len-1;i>=0;i--)
		for(j=0;j<=3;j++)
		{
			for(c=0;c<r[i+1];c++)//next digit
				f[i][j][0]+=f[i+1][j+(c!=0)][1];
			f[i][j][0]+=f[i+1][j+(r[i+1]!=0)][0];
			for(c=0;c<10;c++)
				f[i][j][1]+=f[i+1][j+(c!=0)][1];
		}
	return f[0][0][0];
}
signed main()
{
	int T,l,r;
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<endl;
	}
}