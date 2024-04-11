#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=110;
int cnt=0;
char s[N*N][N];
void query(int l,int r){
	if(l<=r){
		printf("? %d %d\n",l,r);
	}
	fflush(stdout);
	cnt=0;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			scanf("%s",s[cnt++]);
			if(s[cnt-1][0]=='-'){
				exit(0);
			}
		}
	}
}
void answer(const char *ans){
	printf("! %s\n",ans);
	fflush(stdout);
}
typedef map<char,int> MCI;
ostream &operator<<(ostream &o,MCI s){
	o<<"{";
	for(MCI::iterator it=s.begin();it!=s.end();it++){
		if(it->second>0){
			o<<" "<<it->first<<":"<<it->second;
		}
	}
	o<<" }";
	return o;
}
MCI cont(const char *s){
	MCI res;
	for(const char *t=s;*t!='\0';t++){
		res[*t]++;
	}
	return res;
}
void add(MCI &a,MCI b){
	for(char i='a';i<='z';i++){
		a[i]+=b[i];
	}
}
void sub(MCI &a,MCI b){
	for(char i='a';i<='z';i++){
		a[i]-=b[i];
	}
}
MCI result[3][N];
struct E{
	int v;
	MCI s;
};
typedef vector<E> VE;
VE es[N];
void ae(int u,int v,MCI s){
	es[u].push_back({v,s});
}
int is[N];
bool vis[N];
char ans[N]="????????????????????????????";
void process(int id,int l,int r){
	int len=r-l+1;
	int dep=(len+1)/2;
	for(int i=0;i<cnt;i++){
		add(result[id][strlen(s[i])],cont(s[i]));
	}
	for(int i=dep;i>=2;i--){
		sub(result[id][i],result[id][i-1]);
	}
	for(int i=1;i<=dep;i++){
		if(i+1<=dep){
			sub(result[id][i],result[id][i+1]);
		}
		ae(l+i-1,r-i+1,result[id][i]);
		ae(r-i+1,l+i-1,result[id][i]);
	}
}
int n;
void dfs(int x,char c){
	int l=es[x].size();
	for(int i=0;i<l;i++){
		E e=es[x][i];
		if(!vis[e.v]){
			vis[e.v]=true;
			is[e.v]=e.s[c]-is[x];
			dfs(e.v,c);
		}
	}
}
void solve(char c){
	memset(is,0,sizeof is);
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int l=es[i].size();
			for(int j=0;j<l;j++){
				E e=es[i][j];
				if(e.v==i&&!vis[i]){
					vis[i]=true;
					is[i]=e.s[c];
					dfs(i,c);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			exit(1);
		}
		if(is[i]>0){
			ans[i]=c;
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n%2==1){
		int mid=(n+1)/2;
		query(1,n);
		process(0,1,n);
		query(1,mid);
		process(1,1,mid);
		query(mid+1,n);
		process(2,mid+1,n);
		for(char c='a';c<='z';c++){
			solve(c);
		}
	}
	else{
		int mid=(n+1)/2;
		query(1,n);
		process(0,1,n);
		query(1,mid);
		process(1,1,mid);
		query(mid,n);
		process(2,mid,n);
		for(char c='a';c<='z';c++){
			solve(c);
		}
	}
	ans[n+1]='\0';
	answer(ans+1);
	return 0;
}