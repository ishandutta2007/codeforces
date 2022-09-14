#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
char S[1<<17];
long long X,Y;
long long ans=9e18;
int cnt[2][1<<17];
int N;
main()
{
	scanf("%s\n%lld%lld",S,&X,&Y);
	N=strlen(S);
	long long base=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='0')base+=Y*cnt[1][i];
		else if(S[i]=='1')base+=X*cnt[0][i];
		cnt[0][i+1]=cnt[0][i];
		cnt[1][i+1]=cnt[1][i];
		if(S[i]!='?')cnt[S[i]-'0'][i+1]++;
	}
	vector<pair<long long,long long> >pos;
	long long all=0,cumsum=0;
	for(int i=0;i<N;i++)if(S[i]=='?')
	{
		long long zero=cnt[1][i]*Y+(cnt[1][N]-cnt[1][i])*X;
		long long one=cnt[0][i]*X+(cnt[0][N]-cnt[0][i])*Y;
		pos.push_back(make_pair(zero,one));
		all+=zero+one;
		cumsum+=one;
	}
	ans=min(ans,min(all-cumsum,cumsum));
	for(int i=0;i<pos.size();i++)
	{
		cumsum-=pos[i].second;
		cumsum+=pos[i].first;
		long long pr=(long long)(i+1)*(long long)(pos.size()-i-1);
		ans=min(ans,min(all-cumsum+pr*Y,cumsum+pr*X));
	}
	printf("%lld\n",base+ans);
}