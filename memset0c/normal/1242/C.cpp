#include<bits/stdc++.h>
#define ll long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=16,M=5e3+10,K=75010,P=1<<15;
ll sum,s[N],del[N];
bool mrk[P];
std::map<ll,int> map;
std::vector<std::tuple<int,int,int>> sol[P];
int k,cnt,n[N],b[N],a[N][M],id[N][M],ii[K],jj[K],nxt[K];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(k);
	for(int i=1;i<=k;i++){
		read(n[i]);
		for(int j=1;j<=n[i];j++){
			read(a[i][j]),s[i]+=a[i][j],sum+=a[i][j];
		}
	}
	if(sum%k){puts("No");return 0;}
	for(int i=1;i<=k;i++){
		del[i]=sum/k-s[i];
		for(int j=1;j<=n[i];j++){
			map[a[i][j]]=id[i][j]=++cnt;
			ii[cnt]=i,jj[cnt]=j;
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n[i];j++){
			auto it=map.find(a[i][j]+del[i]);
			nxt[id[i][j]]=it==map.end()?0:it->second;
			// printf("> %d %d : %d %d : %d\n",i,j,a[i][j],del[i],nxt[id[i][j]]);
		}
	for(int i=1;i<=k;i++)
		for(int j=1,u,fl,x;j<=n[i];j++){
			fl=true,u=id[i][j],x=0;
			do{
				if((x>>(ii[u]-1))&1){fl=false;break;}
				x^=1<<(ii[u]-1);
				u=nxt[u];
			}while(u&&u!=id[i][j]);
			if(u&&fl&&!mrk[x]){
				mrk[x]=1,u=id[i][j];
				do{
					sol[x].push_back(std::make_tuple(ii[nxt[u]],a[ii[nxt[u]]][jj[nxt[u]]],ii[u]));
					// sol[x].push_back(std::make_tuple(ii[u],a[ii[u]][jj[u]],ii[nxt[u]]));
					u=nxt[u];
				}while(u&&u!=id[i][j]);
				// printf(">> %d %d | %d %d\n",x,sol[x].size(),id[i][j],nxt[id[i][j]]);
			}
		}
	for(int x=0;x<(1<<k);x++)if(mrk[x]){
		cnt=0;
		for(int i=0;i<k;i++)if((x>>i)&1^1)b[cnt++]=i;
		for(int p=0,y=0;p<(1<<cnt);p++){
			y=0;
			for(int i=0;i<cnt;i++)y|=((p>>i)&1)<<b[i];
			if(mrk[y]&&!mrk[x|y]){
				mrk[x|y]=1;
				for(auto it:sol[x])sol[x|y].push_back(it);
				for(auto it:sol[y])sol[x|y].push_back(it);
			}
		}
	}
	if(mrk[(1<<k)-1]){
		puts("Yes");
		std::sort(sol[(1<<k)-1].begin(),sol[(1<<k)-1].end());
		// std::cerr<<sol[(1<<k)-1].size()<<std::endl;
		for(const auto &it:sol[(1<<k)-1]){
			printf("%d %d\n",std::get<1>(it),std::get<2>(it));
			// printf("[%d] %d %d\n",std::get<0>(it),std::get<1>(it),std::get<2>(it));
		}
	}else{
		puts("No");
	}
}