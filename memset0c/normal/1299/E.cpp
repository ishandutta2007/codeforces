#include<bits/stdc++.h>
const int N=810;
int n,a[N],p[N],col[N],loc[N];
std::vector<int> mod,res[N];
std::map<std::vector<int>,int> map;
std::vector<std::pair<int,int>> num;
std::mt19937 rng(20040725^std::chrono::steady_clock::now().time_since_epoch().count());
struct vi:std::vector<int>{
	using std::vector<int>::vector;
	inline vi operator+(const vi &rhs)const{
		vi tem=vi(this->begin(),this->end());
		tem.insert(tem.end(),rhs.begin(),rhs.end());
		return tem;
	}
	inline vi operator-(const vi &rhs)const{
		vi tem=vi(this->begin(),this->end());
		for(int i=0;i<rhs.size();i++){
			auto it=std::find(tem.begin(),tem.end(),rhs[i]);
			if(it!=tem.end())tem.erase(it);
		}
		return tem;
	}
}pre[9][9];
inline vi range(int l,int r){
	vi res;
	for(int i=l;i<r;i++)res.push_back(i);
	return res;
}
bool query(const vi &a){
#ifdef memset0
	int sum=0;
	for(int x:a)sum=(sum+loc[x])%a.size();
	return sum==0;
#endif
	static int res;
	if(a.size()==1)return true;
	printf("? %lu ",a.size());
	for(int i=0;i<a.size();i++)printf("%d%c",a[i]," \n"[i+1==a.size()]);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
void getNumber(int x){
	for(int k,i=1;i<=n;i++)if(!a[i])
		if(query(range(1,i)+range(i+1,n+1)-vi(p+1,p+x)-vi(p+n-x+2,p+n+1))){
			if(p[x])k=n+1-x;
			else if(p[n+1-x])k=x;
			else if(x==1)k=1;
			else k=(query(vi{p[1],i})^(x&1))?n+1-x:x;
			a[i]=k,p[k]=i;
			if(p[x]&&p[n+1-x])return;
		}
}
void getModule(int mod){
	if(mod!=8){
		auto eval=[&](int x){
			vi vec=pre[mod][mod-x];
			assert(vec.size());
			for(int i=1;i<=n;i++)
				if(!col[i]&&query(vec+vi{i})){
					col[i]=x;
				}
		};
		std::fill(col+1,col+n+1,0);
		for(int i=1;i<=n;i++)if(a[i])col[i]=(a[i]-1)%mod+1;
		for(int i=1;i<=mod;i++)eval(i);
		for(int i=1;i<=n;i++)res[i].push_back(col[i]%mod);
	}else{
		auto eval=[&](int mod,int x,std::vector<int> all){
			for(int i:all)col[i]=a[i]?(a[i]-1)%mod+1:0;
			vi vec=pre[mod][mod-x];
			assert(vec.size());
			// printf("!!! %d %d => %d | %d %d\n",mod,x,(x+(mod>>1)-1)%mod+1,p[x],a[p[x]]);
			for(int i:all) 
				if(!col[i]&&query(vec+vi{i})){
					col[i]=x;
				}
			vi res;
			for(int i:all)if(col[i]==x)res.push_back(i);
			return res;
		};
		vi set[9][9];
		set[1][1]=range(1,n+1);
		for(int k=2;k<=mod;k<<=1)
			for(int i=1;(i<<1)<=k;i++)
				if(pre[k][k-i].size()){
					set[k][i]=eval(k,i,set[k>>1][i]);
					set[k][i+(k>>1)]=set[k>>1][i]-set[k][i];
				}else{
					set[k][i+(k>>1)]=eval(k,i+(k>>1),set[k>>1][i]);
					set[k][i]=set[k>>1][i]-set[k][i+(k>>1)];
				}
		for(int i=1;i<=mod;i++)for(int x:set[mod][i])res[x].push_back(i%mod);
	}
}
void quit(){
	if(a[1]>n/2)for(int i=1;i<=n;i++)a[i]=n+1-a[i];
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	exit(0);
}
int main(){
	scanf("%d",&n);
	mod=n<=200?std::vector<int>{3,5,7}:std::vector<int>{3,5,7,8};
#ifdef memset0
	for(int i=1;i<=n;i++)loc[i]=i;
	std::shuffle(loc+1,loc+n+1,rng);
	if(loc[1]>n/2)for(int i=1;i<=n;i++)loc[i]=n+1-loc[i];
	for(int i=1;i<=n;i++)printf("%d%c",loc[i]," \n"[i==n]);
#endif
	if(n<=32){
		for(int i=1;(i<<1)<=n;i++)getNumber(i);
		quit();
	}
	for(int i=1;i<=4;i++){
		getNumber(i);
		num.push_back({i,p[i]});
		num.push_back({n+1-i,p[n+1-i]});
	}
	for(int x=0;x<(1<<num.size())-1;x++){
		int k=__builtin_popcount(x)+1,s=0;
		for(int i=0;i<num.size();i++)if((x>>i)&1)s=(s+num[i].first)%k;
		if(pre[k][s].size())continue;
		for(int i=0;i<num.size();i++)if((x>>i)&1)pre[k][s].push_back(num[i].second);
	}
	for(int i=1;i<=n;i++){
		std::vector<int> tem;
		for(int p:mod)tem.push_back(i%p);
		map[tem]=i;
	}
	for(int v:mod)getModule(v);
	for(int i=1;i<=n;i++)if(!a[i])a[i]=map[res[i]];
#ifdef memset0
	for(int i=1;i<=n;i++){
		printf("[%3d]%4d%4d => ",i,a[i],loc[i]);
		for(int j=0;j<res[i].size();j++)printf("%d%c",res[i][j]," \n"[j+1==res[i].size()]);
	}
#endif
	quit();
}