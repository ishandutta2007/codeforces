#include<bits/stdc++.h>
#define mp std::make_pair
// #define log(...) (void(0))
#define log(...) fprintf(stderr,__VA_ARGS__)
#define debug log("\33[2mPassing [%s] in LINE %d\33[0m\n",__FUNCTION__,__LINE__);
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool mrk=0;
	while(!isdigit(c))mrk^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(mrk)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=1e6+10,M=1e4+10,G=1e3+10;
int n,m,g,r,p[N],d[M],f[M][G];
std::vector<std::pair<int,int>> q,nq;

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	memset(f,-1,sizeof(f));
	read(n),read(m);
	for(int i=1;i<=m;i++)read(d[i]),p[d[i]]=i;
	read(g),read(r);
	std::sort(d+1,d+m+1);
	f[1][0]=0;
	q.push_back(mp(1,0));
	for(int t=0;;t^=1){
		if(!q.size())break;
		for(int i=0;i<q.size();i++){
			auto x=q[i];
			for(int j=std::max(1,x.first-1);j<=std::min(m,x.first+1);j++){
				auto y=mp(j,x.second+std::abs(d[x.first]-d[j]));
				if(y.second<g&&f[y.first][y.second]==-1){
					f[y.first][y.second]=f[x.first][x.second];
					// printf("[%d %d] -> [%d %d] : %d\n",x.first,x.second,y.first,y.second,f[y.first][y.second]);
					q.push_back(y);
				}
			}
		}
		for(int i=0;i<q.size();i++){
			auto x=q[i];
			for(int j=std::max(1,x.first-1);j<=std::min(m,x.first+1);j++){
				auto y=mp(j,x.second+std::abs(d[x.first]-d[j]));
				if(y.second==g&&f[y.first][0]==-1){
					y.second=0;
					f[y.first][y.second]=f[x.first][x.second]+1;
					// printf("[%d %d] -> [%d %d] : %d\n",x.first,x.second,y.first,y.second,f[y.first][y.second]);
					nq.push_back(y);
				}
			}
		}
		q.swap(nq),nq.clear();
	}
	long long ans=LLONG_MAX;
	if(f[m][0]!=-1){
		ans=std::min(ans,(long long)f[m][0]*(g+r)-r);
	}
	for(int i=1;i<g;i++)if(f[m][i]!=-1){
		ans=std::min(ans,(long long)f[m][i]*(g+r)+i);
	}
	// for(int i=0;i<g;i++)if(f[m][i]!=-1)printf("f[%d][%d] = %d\n",m,i,f[m][i]);
	// for(int i=1;i<=m;i++)
	// 	for(int j=0;j<g;j++)if(f[i][j]!=-1){
	// 		printf("f[%d][%d] = %d\n",i,j,f[i][j]);
	// 	}
	printf("%lld\n",ans==9223372036854775807ll?-1:ans);
}