#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int a[20],n,m,x,d[20],e[20],b[20],l=0,l2=0,ans=0,c[15];
bool check1(int num)
{
	for(int i=num;i>=1;i--)
	{
		for(int j=9;j>d[i];j--)if(a[j])return true;
		if(a[d[i]])a[d[i]]--;else return false;
	}return true;
}
bool check2(int num)
{//if(b[5]==1&&b[1]==1&&b[6]==1)cout<<num<<" "<<a[e[num]]<<endl;
	for(int i=num;i>=1;i--)
	{
		for(int j=0;j<e[i];j++)if(a[j])return true;
		if(a[e[i]])a[e[i]]--;else return false;
	}return true;
}
bool check(int num)
{
	//if(b[5]==1&&b[1]==1&&b[6]==1)cout<<num<<endl;
	for(int i=d[num]+1;i<=e[num]-1;i++)if(a[i]){
		return true;
	}
	if(num==0)
	{
		return true;
	}
	if(d[num]==e[num])
	{
		if(!a[d[num]])return false;
		a[d[num]]--;
		if(check(num-1)){return true;}
		else return false;
	}//cout<<d[num]<<" "<<num<<" "<<a[0]<<endl;
	if(a[d[num]])
	{
		for(int i=0;i<=9;i++)c[i]=a[i];
		a[d[num]]--;if(check1(num-1)){return true;}
		for(int i=0;i<=9;i++)a[i]=c[i];
	}
	if(a[e[num]])
	{
		a[e[num]]--;if(check2(num-1)){return true;}
	}return false;
}
void dfs(int x,int num)
{
	if(l<num)return;
	for(int i=1;i<=9;i++)a[i]=b[i];a[0]=l-num;
	if(check(l))
	{
		ans++;//cout<<l-num<<" ";
		//for(int i=1;i<=9;i++)cout<<b[i]<<" ";puts("");
	}
	for(int i=x;i<=9;i++)
		b[i]++,dfs(i,num+1),b[i]--;
}
signed main()
{
	n=read(),m=read();int k=m,g=n;
	while(k)l++,e[l]=k%10,k=k/10;
	while(g)l2++,d[l2]=g%10,g=g/10;
	for(int i=1;i<=9;i++)
		b[i]++,dfs(i,1),b[i]--;
	cout<<ans;
	return 0;
 }