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
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=200005,inf=1e9;
int n,ans,a[N],b[N];
inline int d(int x,int y){return abs(a[x]-a[y])+abs(x-y);}
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();ans=0;
		rep(i,1,n)a[i]=rd();
		rep(i,1,n)
		{
			rep(j,1,4)
			{
				if(i+j-1>n)break;
				if(j<=2){ans++;continue;} 
				rep(k,1,j)b[k]=k;
				int ff=1;
				do
				{
					int x=i+b[1]-1,y=i+b[2]-1,z=i+b[3]-1;
					if(d(x,y)==d(x,z)-d(y,z)){ff=0;break;}
				}while(std::next_permutation(b+1,b+j+1));
				if(ff)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}