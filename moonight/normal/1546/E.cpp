#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define mp make_pair
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
const int N=505,P=998244353;
int n,x,y,s,t,a[N*2][N],b[N][N],f[N];
std::vector<int>c[N][N];
std::vector<std::pair<int,int> >q; 
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();s=0;
		rep(i,1,n)rep(j,1,n)b[i][j]=0;
		rep(i,1,n)rep(j,1,n)c[i][j].clear();
		rep(i,1,n*2)f[i]=0;
		rep(i,1,n*2)rep(j,1,n)a[i][j]=rd();
		rep(i,1,n*2)rep(j,1,n)b[j][a[i][j]]++,c[j][a[i][j]].push_back(i);
		int ql=0,qr=0,cnt=0,id=1,ans=1;q.clear();
		rep(i,1,n)rep(j,1,n)if(b[i][j]==1){qr++;q.push_back(std::mp(i,j));}
		while(cnt<n)
		{
			if(ql<qr)
			{
				x=q[ql].X;y=q[ql].Y;
				if(b[x][y]!=1){ql++;continue;}
				fore(i,c[x][y])if(!f[c[x][y][i]]){t=c[x][y][i];break;}
			}
			else
			{
				while(f[id])id++;
				t=id;ans=2ll*ans%P;
			}
			f[t]=1;cnt++;
			rep(i,1,n)b[i][a[t][i]]=0;
			rep(i,1,n)
			{
				fore(j,c[i][a[t][i]])
				{
					s=c[i][a[t][i]][j];
					if(!f[s])
					{
						f[s]=2;
						rep(k,1,n)
						{
							b[k][a[s][k]]--;
							if(b[k][a[s][k]]==1){qr++;q.push_back(std::mp(k,a[s][k]));}
						}
					}
				}
			}
			ql++;
		}
        printf("%d\n",ans);
        rep(i,1,n*2)if(f[i]==1)printf("%d ",i);
        puts("");
	}
	return 0;
}