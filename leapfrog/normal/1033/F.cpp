//Coded by leapfrog {{{
//Coded on 2021.10.26
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int w,n,m,a[4096],A[4096];char ch[12];
inline void fwt(int n,int *a,char fg)
{
	for(int d=1,q=0;d<n;d<<=1,q++) for(int i=0;i<n;i+=(d<<1)) for(int j=i;j<i+d;j++)
		if(ch[q]=='O'||ch[q]=='o') a[j|d]=(fg?a[j|d]-a[j]:a[j|d]+a[j]);
		else if(ch[q]=='A'||ch[q]=='a') a[j]=(fg?a[j]-a[j|d]:a[j]+a[j|d]);
		else {int x=a[j],y=a[j|d];a[j]=fg?(x+y)/2:x+y,a[j|d]=fg?(x-y)/2:x-y;}
}
int main()
{
	read(w,n,m);for(int x;n--;) read(x),a[x]++;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",ch),reverse(ch,ch+w),memcpy(A,a,sizeof(A));
		fwt(1<<w,A,0);
		//for(int i=0;i<(1<<w);i++) printf("%d%c",A[i],i==(1<<w)-1?'\n':' ');
		for(int i=0;i<(1<<w);i++) A[i]*=A[i];
		fwt(1<<w,A,1);int ps=0;
		for(int i=0;i<w;i++) if(ch[i]>=97) ps^=(1<<i);
		printf("%d\n",A[ps]);
	}return 0;
}