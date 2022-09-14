#include<cstdio>
#include<vector>
using namespace std;
int T;
int N;
void output(const vector<int>&L)
{
	for(int i=0;i<L.size();i++)printf("%d%c",L[i]+1,i+1==L.size()?10:32);
}
int ask(const vector<int>&L,const vector<int>&R)
{
	printf("? %d %d\n",L.size(),R.size());
	output(L);
	output(R);
	fflush(stdout);
	int F;
	scanf("%d",&F);
	return F;
}
int ask(int fn,int l,int r)
{
	vector<int>L{fn},R;R.reserve(r-l);
	for(int i=l;i<r;i++)R.push_back(i);
	return ask(L,R);
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int fn=-1,fnF;
		for(int i=1;i<N;i++)
		{
			vector<int>L{i},R;R.reserve(i);
			for(int j=0;j<i;j++)R.push_back(j);
			int F=ask(L,R);
			if(F!=0)
			{
				fn=i;
				fnF=F;
				break;
			}
		}
		vector<int>zero;
		for(int i=fn+1;i<N;i++)
		{
			vector<int>L{fn},R{i};
			int F=ask(L,R);
			if(F==0)zero.push_back(i);
		}
		{
			int L=0,R=fn;
			while(R-L>1)
			{
				int mid=(L+R)/2;
				if(ask(fn,L,mid)!=0)R=mid;
				else L=mid;
			}
			for(int i=0;i<fn;i++)if(i!=L)zero.push_back(i);
		}
		printf("! %d ",zero.size());
		output(zero);
		fflush(stdout);
	}
}