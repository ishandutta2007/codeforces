#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
struct P{
	int x,y,z,id;
	bool operator<(const P&A)const{
		return x!=A.x?x<A.x:y!=A.y?y<A.y:z!=A.z?z<A.z:id<A.id;
	}
};
P X[50505];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",&X[i].x,&X[i].y,&X[i].z);
		X[i].id=i+1;
	}
	sort(X,X+N);
	vector<int>A;
	for(int i=0;i<N;)
	{
		int j=i+1;
		while(j<N&&X[i].x==X[j].x)j++;
		if(j-i==1)
		{
			A.push_back(X[i].id);
			i=j;
			continue;
		}
		vector<int>B;
		for(int k=i;k<j;)
		{
			int l=k+1;
			while(l<j&&X[k].y==X[l].y)l++;
			for(;k+1<l;k+=2)
			{
				printf("%d %d\n",X[k].id,X[k+1].id);
			}
			if(l-k==1)
			{
				B.push_back(X[k].id);
			}
			k=l;
		}
		int k=0;
		for(;k+1<B.size();k+=2)printf("%d %d\n",B[k],B[k+1]);
		if(k<B.size())A.push_back(B[k]);
		i=j;
	}
	for(int i=0;i+1<A.size();i+=2)printf("%d %d\n",A[i],A[i+1]);
}