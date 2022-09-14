#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int N,P[2<<17],id[2<<17];
long long ans;
set<int>S;
main()
{
	scanf("%d",&N);
	S.insert(-1);
	S.insert(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",P+i);
		id[P[i]]=i;
	}
	for(int i=N;i;i--)
	{
		int L,R;
		set<int>::iterator it=S.lower_bound(id[i]);
		R=*it;
		it--;
		L=*it;
		int I=id[i];
		if(I-L>R-I)
		{
			for(int j=I+1;j<R;j++)
			{
				if(id[i-P[j]]<I&&L<id[i-P[j]])ans++;
			}
		}
		else
		{
			for(int j=L+1;j<I;j++)
			{
				if(id[i-P[j]]>I&&R>id[i-P[j]])ans++;
			}
		}
		S.insert(I);
	}
	cout<<ans<<endl;
}