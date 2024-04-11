//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int a[7],t[7];
int main()
{
	for(int i=1;i<=6;i++) scanf("%1d",a+i);
	int sm1=a[1]+a[2]+a[3],sm2=a[4]+a[5]+a[6];
	if(sm1>sm2) t[1]=a[1],t[2]=a[2],t[3]=a[3],t[4]=9-a[4],t[5]=9-a[5],t[6]=9-a[6];
	else t[1]=9-a[1],t[2]=9-a[2],t[3]=9-a[3],t[4]=a[4],t[5]=a[5],t[6]=a[6];
	sort(t+1,t+6+1,greater<int>());int tmp=abs(sm1-sm2),cnt=1;
//	printf("%d : ",tmp);for(int i=1;i<=6;i++) printf("%d%c",t[i],i==6?'\n':' ');
	while(tmp>0) tmp-=t[cnt++];
	return printf("%d\n",cnt-1),0;
}