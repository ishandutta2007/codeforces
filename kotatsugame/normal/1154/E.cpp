#include<cstdio>
#include<set>
using namespace std;
int N,K;
int A[2<<17],invA[2<<17];
bool ex[2<<17];
char ans[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	set<pair<int,int> >S;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		invA[A[i]]=i;
		ex[i]=true;
		S.insert(make_pair(i,A[i]));
	}
	for(int tm=0,nxt=N-1;;tm++)
	{
		while(nxt>=0&&!ex[nxt])nxt--;
		if(nxt<0)break;
		int id=invA[nxt];
		auto it=S.lower_bound(make_pair(id,0));
		for(int j=0;j<=K;j++)
		{
			ans[it->first]=tm%2+1;
			ex[it->second]=false;
			it=S.erase(it);
			if(it==S.end())break;
		}
		for(int j=0;j<K;j++)
		{
			if(it==S.begin())break;
			it--;
			ans[it->first]=tm%2+1;
			ex[it->second]=false;
			it=S.erase(it);
		}
	}
	for(int i=0;i<N;i++)putchar(ans[i]+'0');
	puts("");
}