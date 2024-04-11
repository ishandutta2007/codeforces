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
const int N=110;
int n,m,l,r,col[N],vis[N],q[N];
std::vector<std::pair<int,std::pair<int,int>>> G[N];
struct atom{
	int a[26],len;
}res[N],cur,all,pri[N];
std::map<atom,int> map;
inline atom operator+(const atom &a,const atom &b){
	atom c;
	for(int i=0;i<26;i++)c.a[i]=a.a[i]+b.a[i];
	return c;
}
inline atom operator-(const atom &a,const atom &b){
	atom c;
	for(int i=0;i<26;i++)c.a[i]=a.a[i]-b.a[i];
	return c;
}
inline atom operator*(const atom &a,int b){
	atom c;
	for(int i=0;i<26;i++)c.a[i]=a.a[i]*b;
	return c;
}
inline void read(atom &x){
	std::string s;
	std::cin>>s;
	for(int i=0;i<s.length();i++)x.a[s[i]-'a']++;
	x.len=s.length();
}
inline void add(int l,int r,int x,int y){
	// printf("add %d %d %d %d\n",l,r,x,y);
	if(l==r){
		assert(x==y);
		vis[l]=1;
		col[l]=x;
		return;
	}
	G[l].push_back(std::make_pair(r,std::make_pair(x,y)));
	G[r].push_back(std::make_pair(l,std::make_pair(x,y)));
}
void solve(int l,int r){
	printf("? %d %d\n",l,r);
	int m=r-l+1;
	std::vector<atom> res(m*(m+1)/2);
	for(int i=0;i<res.size();i++)read(res[i]);
	for(int i=0;i<res.size();i++)if(res[i].len==m)all=res[i];
	for(int i=1;i<=((m+1)>>1);i++){
		cur=all*(i+1);
		// for(int i=0;i<26;i++)print(cur.a[i]," \n"[i==25]);
		for(auto x:res)if(x.len==m-i)cur=cur-x;
		// for(int i=0;i<26;i++)print(cur.a[i]," \n"[i==25]);
		for(int j=1;j<i;j++)cur=cur-pri[j]*(i-j+1);
		// for(int i=0;i<26;i++)print(cur.a[i]," \n"[i==25]);
		pri[i]=cur;
		for(int ii=0;ii<26;ii++)if(cur.a[ii]){
			cur.a[ii]--;
			for(int jj=ii;jj<26;jj++)if(cur.a[jj]){
				add(l+i-1,r-i+1,ii,jj);
				break;
			}
			break;
		}
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	if(n==1){
		printf("? 1 1\n");
		std::string s;
		std::cin>>s;
		std::cout<<"! "<<s<<std::endl;
		return 0;
	}
	solve(1,n),solve(1,n>>1);
	(n&1)?solve((n>>1)+1,n):solve(n>>1,n);
	l=1;
	for(int i=1;i<=n;i++)if(vis[i])q[++r]=i;
	while(l<=r){
		int u=q[l++];
		// printf(">> %d\n",u);
		for(auto it:G[u]){
			int v=it.first,w=col[u]==it.second.first?it.second.second:it.second.first;
			if(!vis[v]){
				vis[v]=1,col[v]=w;
				q[++r]=v;
			}
			assert(col[v]==w);
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)putchar(col[i]+'a');
	putchar('\n');
}