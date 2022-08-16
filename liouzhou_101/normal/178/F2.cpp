#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int MaxN=2010;

int n,k;
string s[MaxN];
int h[MaxN];

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>s[i];
	sort(s+1,s+n+1);
	for (int i=2;i<=n;++i)
		for (;h[i]<min(s[i-1].length(),s[i].length())&&s[i-1][h[i]]==s[i][h[i]];++h[i]);
}

int tot;
int F[MaxN][MaxN];

int solve(int L,int R)
{
	if (L==R) return MaxN-1;
	int now=++tot;
	int mid=min_element(h+L+1,h+R+1)-h;
	int x=solve(L,mid-1),y=solve(mid,R);
	for (int i=0;i<=mid-L;++i)
		for (int j=0;j<=R-mid+1;++j)
			F[now][i+j]=max(F[now][i+j],F[x][i]+F[y][j]+h[mid]*i*j);
	return now;
}

void work()
{
	cout<<F[solve(1,n)][k]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}