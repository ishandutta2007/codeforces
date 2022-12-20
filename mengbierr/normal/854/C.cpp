#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct data
{
	int tim;
	int val;
}a[300005];
int t[300005];
bool operator < (data x,data y)
{
	return x.val<y.val;
}
priority_queue<data> q;
long long ans;
int main()
{
	int n=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		a[i].val=read();
		data temp;
		temp.val=a[i].val;
		temp.tim=i;
		q.push(temp);
	}
	for(int i=k+1;i<=n;i++)
	{
		a[i].val=read();
		data temp;
		temp.val=a[i].val;
		temp.tim=i;
		q.push(temp);
		temp=q.top();
		q.pop();
		t[temp.tim]=i;
		ans+=1LL*temp.val*(i-temp.tim);
	}
	for(int i=n+1;i<=n+k;i++)
	{
		data temp;
		temp=q.top();
		q.pop();
		t[temp.tim]=i;
		ans+=1LL*temp.val*(i-temp.tim);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	printf("%d ",t[i]);
}