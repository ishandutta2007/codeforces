#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005;
int n,a[N];
int main()
{
	int T=rd();
	while(T--)
	{
		int ff=1;n=rd();rep(i,1,n)a[i]=rd();
		std::vector<int>V1,V2;V1.clear();V2.clear();
		for(int i=1;i<=n;i+=2)V1.push_back(a[i]);
		for(int i=2;i<=n;i+=2)V2.push_back(a[i]);
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		fore(i,V1)a[2*i+1]=V1[i];
		fore(i,V2)a[2*i+2]=V2[i];
		rep0(i,1,n)if(a[i]>a[i+1])ff=0;
		puts(ff?"YES":"NO");
	}
	return 0;
}