#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=4e5+10;
int n,m,x,y,rr,cc,ans,sum,a[N],b[N],c[N],pre[N];
std::vector<int> que;
std::vector<std::vector<int>> res;
std::vector<std::pair<int,int>> vet;
bool check(){
	for(auto line:res)for(auto num:line)if(!num)return false;
	for(auto line:res)for(auto num:line)if(--c[num]<0)return false;
	memset(c,0,sizeof(c));
	for(int i=0;i<rr;i++){
		for(int j=0;j<cc;j++)if(++c[res[i][j]]>1)return false;
		for(int j=0;j<cc;j++)if(--c[res[i][j]]>1)return false;
	}
	for(int j=0;j<cc;j++){
		for(int i=0;i<rr;i++)if(++c[res[i][j]]>1)return false;
		for(int i=0;i<rr;i++)if(--c[res[i][j]]>1)return false;
	}
	return true;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),b[i]=a[i];
	std::sort(b+1,b+n+1);
	// for(int i=1;i<=n;i++)print(b[i]," \n"[i==n]);
	m=std::unique(b+1,b+n+1)-b-1;
	// for(int i=1;i<=n;i++)print(b[i]," \n"[i==m]);
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(b+1,b+m+1,a[i])-b,++c[a[i]];
	for(int i=1;i<=m;i++)vet.push_back(std::make_pair(c[i],i));
	std::sort(vet.begin(),vet.end());
	// for(int i=1;i<=n;i++)print(a[i]," \n"[i==n]);
	// for(int i=0;i<vet.size();i++)printf("[%d %d]%c",vet[i].first,vet[i].second," \n"[i==vet.size()-1]);
	for(int r=1,c;r*r<=n;r++){
		sum=0;
		for(int i=0;i<vet.size();i++)sum+=std::min(vet[i].first,r);
		c=sum/r;
		// printf("r=%d c=%d sum=%d\n",r,c,sum);
		if(c<r)continue;
		if(r*c>ans)ans=r*c,rr=r,cc=c;
	}
	std::reverse(vet.begin(),vet.end());
	for(auto it:vet){
		for(int x=std::min(rr,it.first);x--;){
			que.push_back(it.second);
		}
	}
	x=0,y=0;
	res.resize(rr);
	for(int i=0;i<rr;i++)res[i].resize(cc);
	for(int i=0;i<ans;i++){
		res[x][y]=que[i];
		x++,y++;
		if(x==rr)x-=rr,y-=rr-1;
		if(y<0)y+=cc;
		if(y>=cc)y-=cc;
	}
	// printf("%d\n",ans);
	printf("%d\n%d %d\n",ans,rr,cc);
	for(auto line:res){
		for(auto num:line)print(b[num],' ');
		putchar('\n');
	}
	// if(!check())std::cerr<<"error!"<<std::endl;
}