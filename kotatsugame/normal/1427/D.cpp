#include<cstdio>
#include<vector>
using namespace std;
int N;
int c[55];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&c[i]);
	vector<vector<int> >ans;
	while(true)
	{
		vector<int>now;
		vector<int>id(N+1,-1);
		for(int i=0;i<N;)
		{
			int j=i+1;
			id[c[i]]=now.size();
			while(j<N&&c[j-1]+1==c[j])
			{
				id[c[j]]=now.size();
				j++;
			}
			now.push_back(j-i);
			i=j;
		}
		if(now.size()==1)break;
		int L,R;
		for(int i=1;i<N;i++)
		{
			if(id[i+1]<id[i])
			{
				L=id[i+1];
				R=id[i];
				break;
			}
		}
		vector<int>tmp;
		if(L>0)
		{
			int sum=0;
			for(int i=0;i<L;i++)sum+=now[i];
			tmp.push_back(sum);
		}
		{
			int sum=0;
			for(int i=L;i<R;i++)sum+=now[i];
			tmp.push_back(sum);
		}
		{
			tmp.push_back(now[R]);
		}
		if(R+1<now.size())
		{
			int sum=0;
			for(int i=R+1;i<now.size();i++)sum+=now[i];
			tmp.push_back(sum);
		}
		ans.push_back(tmp);
		vector<int>newc;
		int cumsum=0;
		for(int i=0;i<tmp.size();i++)
		{
			for(int j=tmp[i];j--;)
			{
				newc.push_back(c[cumsum+j]);
			}
			cumsum+=tmp[i];
		}
		for(int i=0;i<N;i++)c[i]=newc[N-i-1];
	}
	printf("%d\n",(int)ans.size());
	for(const vector<int>&tmp:ans)
	{
		printf("%d",(int)tmp.size());
		for(int id:tmp)printf(" %d",id);
		printf("\n");
	}
}