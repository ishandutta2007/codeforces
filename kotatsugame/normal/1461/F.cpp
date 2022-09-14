#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int A[1<<17];
char S[9];
void rec(int L,int R)
{
	int sum=(R-L)*2;
	int prod=1;
	for(int i=L;i<R;i++)
	{
		prod*=A[i];
		if(prod>=sum)prod=sum;
	}
	if(prod>=sum)
	{
		for(int i=L;i<R;i++)
		{
			if(i>L)printf("*");
			printf("%d",A[i]);
		}
		return;
	}
	vector<pair<int,pair<int,int> > >B;
	for(int i=L;i<R;)
	{
		if(A[i]==1)
		{
			int j=i;
			while(j<R&&A[j]==1)j++;
			B.push_back(make_pair(-(j-i),make_pair(i,j)));
			i=j;
		}
		else
		{
			int j=i;
			int prod=1;
			while(j<R&&A[j]!=1)prod*=A[j++];
			B.push_back(make_pair(prod,make_pair(i,j)));
			i=j;
		}
	}
	int n=B.size()-1;
	int ans=-1,ansbit;
	for(int bit=0;bit<1<<n;bit++)
	{
		int now=B[0].first;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(bit>>i&1)
			{
				if(now<0)now=1;
				if(B[i+1].first>0)now*=B[i+1].first;
			}
			else
			{
				sum+=abs(now);
				now=B[i+1].first;
			}
		}
		sum+=abs(now);
		if(ans<sum)
		{
			ans=sum;
			ansbit=bit;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(B[i].first>0)
		{
			int l=B[i].second.first,r=B[i].second.second;
			for(int j=l;j<r;j++)
			{
				if(j>l)printf("*");
				printf("%d",A[j]);
			}
		}
		else
		{
			bool add=true;
			if(i>0&&ansbit>>i-1&1)add=false;
			if(i<n&&ansbit>>i&1)add=false;
			int l=B[i].second.first,r=B[i].second.second;
			for(int j=l;j<r;j++)
			{
				if(j>l)printf("%c",add?'+':'*');
				printf("%d",A[j]);
			}
		}
		if(i<n)printf("%c",ansbit>>i&1?'*':'+');
	}
}
void func(int L,int R)
{
	bool fst=true;
	while(L<R&&A[L]==1)
	{
		if(fst)fst=false;
		else printf("+");
		printf("1");
		L++;
	}
	if(L==R)return;
	if(!fst)printf("+");
	int r=R;
	while(A[r-1]==1)r--;
	rec(L,r);
	while(r++<R)printf("+1");
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	scanf("\n%s",S);
	int n=strlen(S);
	if(n==1)
	{
		for(int i=0;i<N;i++)
		{
			printf("%d%c",A[i],i+1==N?'\n':S[0]);
		}
	}
	else if(n==2&&(S[0]=='+'&&S[1]=='-'||S[0]=='-'&&S[1]=='+'))
	{
		for(int i=0;i<N;i++)
		{
			printf("%d%c",A[i],i+1==N?'\n':'+');
		}
	}
	else if(n==2&&(S[0]=='-'&&S[1]=='*'||S[0]=='*'&&S[1]=='-'))
	{
		bool flag=false;
		for(int i=0;i<N;i++)
		{
			printf("%d%c",A[i],i+1==N?'\n':A[i+1]==0?'-':'*');
		}
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			if(i!=0)printf("+");
			if(A[i]==0)
			{
				printf("0");
			}
			else
			{
				int j=i+1;
				while(j<N&&A[j]!=0)j++;
				func(i,j);
				i=j-1;
			}
		}
		puts("");
	}
}