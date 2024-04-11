#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<iterator>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const int MOD=1000000009;
int n,x[MAXN],y[MAXN],ans;
pair<int,int> A[MAXN];
map<pair<int,int>,int> M;
set<int> S;
int Bracer(int x,int y)
{
	if(!M[make_pair(x,y)]) return 3;
	if(y==0) return 3;
	int con=0;
	for(int i=-1;i<=1;i++)
		if(M[make_pair(x+i,y-1)]) con++;
	return con;
}
bool is_ok(int x,int y)
{
	if(!M[make_pair(x,y)]) return false;
	bool p=true;
	for(int i=-1;i<=1;i++)
		if(Bracer(x+i,y+1)==1) p=false;
	return p;
}
void Change(int x,int y)
{
	if(!M[make_pair(x,y)]) return;
	if(is_ok(x,y)) S.insert(M[make_pair(x,y)]);
	else S.erase(M[make_pair(x,y)]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),A[i]=make_pair(x[i],y[i]),M[A[i]]=i;
	for(int i=1;i<=n;i++) if(is_ok(x[i],y[i])) S.insert(i);
	for(int i=1;i<=n;i++)
	{
		int X;
		if(i&1) X=(*S.rbegin());
		else X=(*S.begin());
		S.erase(X);
		ans=((LL)ans*n+(LL)X+MOD-1)%MOD;
		M[A[X]]=0;
		for(int i=-2;i<=2;i++) Change(x[X]+i,y[X]);
		for(int i=-1;i<=1;i++) Change(x[X]+i,y[X]-1);
	}
	printf("%d\n",ans);
	return 0;
}