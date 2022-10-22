//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
#define uint unsigned int
namespace getrd{
	uint seed=114514;
	inline uint rd(){
		seed^=(seed<<13);
		seed^=(seed>>17);
		seed^=(seed<<5);
		return seed;
	}
}
using getrd::rd;
inline bool ak(){
	return rd()&1;
}
int c,n,f[1000002],a[1000002],low[1024],tot,P[1000002],TOT;
bool ans[1000002];
vector<int>x[1000002];
bool mark[1000002];
vector<vector<bool> >sol[1000002];
vector<bool>vis[1000002];
inline vector<bool>make_vec(int S,int len){
	vector<bool>rt(len);
	F(i,0,len-1)rt[i]=(S>>i&1);
	return rt;
}
inline vector<bool>make_vec(bitset<260>S,int len){
	vector<bool>rt(len);
	F(i,0,len-1)rt[i]=S[i];
	return rt;
}
#define bp __builtin_popcount
inline void solve(int pos){
	sol[pos].resize(x[pos].size()+1);
	vis[pos].resize(x[pos].size()+1);
	if(x[pos].size()<=10){
		int sz=x[pos].size();
		int temp[1<<sz]={},orz=(a[pos]==0),p=0;
		if(a[pos]==0)sol[pos][0]=make_vec(0,sz);
		F(i,1,(1<<sz)-1){
			temp[i]=temp[i^(i&-i)]^x[pos][low[i]];
			if(temp[i]==a[pos]&&!vis[pos][bp(i)])
				sol[pos][bp(i)]=make_vec(i,sz),vis[pos][bp(i)]=1,++orz,p=bp(i);
		}
		if(orz==1)tot+=p,P[pos]=p;
		//else TOT+=sz;
	}else{
		bitset<260>w[20],temp,lp[260];
		bool orz=0;
		int p[20]={},cnt=0,pp;
		F(i,0,x[pos].size()-1){
			int num=x[pos][i];
			temp.reset();
			temp[i]=1;
			bool tar=0;
			UF(j,19,0)if(num>>j&1){
				if(!p[j]){
					p[j]=num;
					w[j]=temp;
					tar=1;
					break;
				}else{
					temp^=w[j];
					num^=p[j];
				}
			}
			if(!tar)lp[++cnt]=temp;
		}
		int v=a[pos];
		temp.reset();
		UF(i,19,0){
			if(v>>i&1){
				v^=p[i];
				temp^=w[i];
			}
		}
		vis[pos][temp.count()]=1;
		sol[pos][temp.count()]=make_vec(temp,x[pos].size());
		pp=temp.count();
		F(i,1,100){
			F(j,1,cnt)if(ak())temp^=lp[j];
			if(!vis[pos][temp.count()]){
				vis[pos][temp.count()]=1;
				sol[pos][temp.count()]=make_vec(temp,x[pos].size());
				orz=1;
			}
		}
		if(!orz)tot+=pp,P[pos]=pp;
		//else TOT+=x[pos].size();
	}
}
bitset<50002>fuck[10002];
int main() {
//	freopen("data.txt","r",stdin);
//	freopen("qwq.txt","w",stdout);
	F(i,1,1023)low[i]=((i&1)?0:low[i>>1]+1);
	memset(P,0xff,sizeof(P));
	cin>>c>>n;
	F(i,1,c)f[i]=1;
	F(i,2,c){
		if(!mark[i]){
			for(int j=i;j<=c;j+=i){
				mark[j]=1;
				f[j]*=i;
			}
		}
	}
	int query_cnt=0;
	F(i,1,c)x[f[i]].push_back(i),query_cnt+=(f[i]==i);
	//int tot[300]={};
	//F(i,1,c)++tot[x[i].size()];int tott=0;
	//F(i,11,260)tott+=tot[i];
	//cerr<<tott<<endl;return 0;
	//int mmax=0;
	//F(i,1,c)mmax=max(mmax,(int)x[i].size());
	// mmax = 260
	//write(mmax,'\n');
	write(query_cnt,' ');
	F(i,1,c)if(f[i]==i)write(i,' ');puts("");
	fflush(stdout);
	read(a[1]);
	F(i,2,c)if(f[i]==i)a[i]=read()^a[1];
	F(i,2,c)if(f[i]==i)for(int j=i+i;j<=c;j+=i)if(f[j]==j)a[j]^=a[i];
	UF(i,c,2)if(f[i]==i)for(int j=i+i;j<=c;j+=i)a[i]^=a[j];
	F(i,2,c)a[1]^=a[i];
	//F(i,1,c)if(f[i]==i)write(i,' '),write(a[i],'\n');
	F(i,1,c)if(f[i]==i)solve(i);
	int res=n-tot;
	int ccf=0;
	fuck[0][0]=1;
	F(i,1,c)if(f[i]==i){
		if(P[i]==-1){
			++ccf;
			F(j,0,x[i].size())if(vis[i][j]){
				fuck[ccf]|=(fuck[ccf-1]<<j);
			}
		}
	}
	UF(i,c,1)if(f[i]==i){
		if(P[i]==-1){
			--ccf;
			F(j,0,min(res,(int)x[i].size()))if(vis[i][j]&&fuck[ccf][res-j]){
				res-=j;
				F(k,0,x[i].size()-1){
					ans[x[i][k]]=sol[i][j][k];
				}
				break;
			}
		}else{
			int j=P[i];
			F(k,0,x[i].size()-1)ans[x[i][k]]=sol[i][j][k];
		}
	}
	F(i,1,c)if(ans[i])write(i,' ');
	fflush(stdout);
	return 0;
}
/*
10 6
4 4 2 11 4 4 1
*/