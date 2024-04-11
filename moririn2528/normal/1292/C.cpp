#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

class Lca{
private:
	const int M=20;
	int nest=0;
	vector<vector<int>> lca_path;
	vector<vector<int>> lca_par;
	vector<int> lca_depth,lca_size;
	
	void init(int n){
		lca_path.assign(n,vector<int>());
		lca_par.assign(n,vector<int>(M,-1));
		lca_depth.assign(n,-1);
		lca_size.assign(n,0);
	}

	void create_depth(int pos,int bef,int d){
		if(lca_depth.at(pos)!=-1)return;
		lca_depth.at(pos)=d;
		int p=bef;
		for(int i=0;i<M;i++){
			if(p==-1)break;
			lca_par.at(pos).at(i)=p;
			p=lca_par.at(p).at(i);
		}
		for(auto to:lca_path.at(pos)){
			create_depth(to,pos,d+1);
		}
	}

	void create_size(int pos,int bef){
		int s=1;
		for(auto to:lca_path[pos]){
			if(to==bef)continue;
			create_size(to,pos);
			s+=lca_size[to];
		}
		lca_size[pos]=s;
	}

public:
	
	Lca(int n){
		init(n);
	}
	Lca(int n,int nes){
		nest=nes;
		init(n);
	}

	int get_depth(int pos){
		return lca_depth.at(pos);
	}
	
	void connect(int a,int b){
		lca_path.at(a).push_back(b);
		lca_path.at(b).push_back(a);
	}

	void reload(){
		int n=lca_path.size();
		lca_par.assign(n,vector<int>(M,-1));
		lca_depth.assign(n,-1);
		create_depth(nest,-1,0);
		create_size(nest,-1);
	}

	int check_parent(int pos,int dis){
		assert(0<=dis && dis<=lca_depth[pos]);
		if(dis==0)return pos;
		for(int i=M-1;i>=0;i--){
			if(dis<(1<<i))continue;
			dis-=1<<i;
			pos=lca_par.at(pos).at(i);
		}
		return pos;
	}

	int lca(int a,int b){
		if(lca_depth.at(a)<lca_depth.at(b))swap(a,b);
		a=check_parent(a,lca_depth.at(a)-lca_depth.at(b));
		if(a==b)return a;
		for(int i=M-1;i>=0;i--){
			if(lca_par.at(a).at(i)!=lca_par.at(b).at(i)){
				a=lca_par.at(a).at(i);
				b=lca_par.at(b).at(i);
			}
		}
		return lca_par.at(a).at(0);
	}

	int count(int a,int b){
		int c=lca(a,b);
		int n=lca_path.size();
		int x,y;
		if(a!=c)x=lca_size[a];
		else{
			x=check_parent(b,lca_depth[b]-lca_depth[a]-1);
			x=n-lca_size[x];
		}
		if(b!=c)y=lca_size[b];
		else{
			y=check_parent(a,lca_depth[a]-lca_depth[b]-1);
			y=n-lca_size[y];
		}
		return x*y;
	}

	int next(int a,int b){
		int c=lca(a,b);
		if(a!=c)return check_parent(a,1);
		return check_parent(b,lca_depth[b]-lca_depth[a]-1);
	}

	void test(){
		array_show(lca_size);
	}
};

LL dp[3300][3300];
LL check(int a,int b,Lca& la){
	if(a>b)swap(a,b);
	if(dp[a][b]!=-1)return dp[a][b];
	dp[a][b]=0;
	if(a==b)return 0;
	dp[a][b]=max(check(la.next(a,b),b,la),check(a,la.next(b,a),la));
	dp[a][b]+=la.count(a,b);
	return dp[a][b];
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	Lca la(n);
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		la.connect(a,b);
	}
	la.reload();
	memset(dp,-1,sizeof(dp));
	a=0;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			b=check(i,j,la);
			a=max(a,b);
		}
	}
	cout<<a<<endl;
}