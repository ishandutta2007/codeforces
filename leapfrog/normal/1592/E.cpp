#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=2000005,INF=(int)0x3f3f3f3f3f3f3f3f;
int n,a[N],sm[N],mn[N][2],rs;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm[i]=sm[i-1]^a[i];
	int rs=0;memset(mn,0x3f,sizeof(mn));
	for(int bt=20,qz=0;bt>=0;qz|=1<<(bt--))
		for(int i=1,j=1;i<=n;i=j)
		{
			if((a[i]>>bt)&1);else {++j;continue;}
			while(j<=n&&(a[j]>>bt)&1) j++;
			for(int k=i;k<j;k++)
			{
				mn[sm[k-1]&qz][(k-1)&1]=min(mn[sm[k-1]&qz][(k-1)&1],k-1);
				rs=max(rs,k-mn[sm[k]&qz][k&1]);
			}
			for(int k=i;k<j;k++) mn[sm[k-1]&qz][0]=mn[sm[k-1]&qz][1]=INF;
		}
	return printf("%d\n",rs),0;
}
//
// &  1
// xor  0
// 1 
// dp 