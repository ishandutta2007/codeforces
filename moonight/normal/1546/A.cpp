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
const int N=105;
int n,a[N],b[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();int s=0;
		rep(i,1,n)a[i]=rd(),s+=a[i];
		rep(i,1,n)b[i]=rd(),s-=b[i];
		if(s)
		{
			puts("-1");
			continue;
		}
		std::vector<int>V1,V2;
		V1.clear();V2.clear(); 
		rep(i,1,n)
		{
			int t=a[i]-b[i];
			if(t==0)continue;
			if(t>0)
			{
				rep(j,1,t)V1.push_back(i);
				continue;
			}
			t=-t;
			rep(j,1,t)V2.push_back(i);
		} 
		printf("%d\n",(int)V1.size());
		fore(i,V1)printf("%d %d\n",V1[i],V2[i]);
	}
	return 0;
}