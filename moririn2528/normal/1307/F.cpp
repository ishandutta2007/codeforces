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
	vector<int> lca_depth;
	
	void init(int n){
		lca_path.assign(n,vector<int>());
		lca_par.assign(n,vector<int>(M,-1));
		lca_depth.assign(n,-1);
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

};

class union_find_tree{
private:
	static constexpr int uft_N=100005;
	int uft_n;
	queue<int> uft_q1;
	vector<int> uft_parent;
	vector<int> uft_num;
public:
	void init(){
		uft_parent.assign(uft_n,-1);
		uft_num.assign(uft_n,0);
	}
	union_find_tree(int uft_num){
		assert(uft_num>=0);
		uft_n=uft_num;
		init();
	}
	union_find_tree(){
		uft_n=uft_N;
		init();
	}

	int check_parent(int uft_x){
		assert(uft_x>=0 && uft_x<uft_n);
		if(uft_parent[uft_x]!=-1){
			uft_q1.push(uft_x);
			return check_parent(uft_parent[uft_x]);
		}
		int uft_a;
		while(!uft_q1.empty()){
			uft_a=uft_q1.front(),uft_q1.pop();
			uft_parent[uft_a]=uft_x;
		}
		return uft_x;
	}

	bool connect(int uft_x,int uft_y){
		assert(uft_x>=0 && uft_x<uft_n);
		assert(uft_y>=0 && uft_y<uft_n);
		uft_x=check_parent(uft_x),uft_y=check_parent(uft_y);
		if(uft_x==uft_y)return true;
		if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
		uft_parent[uft_x]=uft_y;
		uft_num[uft_y]+=uft_num[uft_x];
		return false;
	}

	bool check_connect(int uft_x,int uft_y){
		assert(uft_x>=0 && uft_x<uft_n);
		assert(uft_y>=0 && uft_y<uft_n);
		uft_x=check_parent(uft_x),uft_y=check_parent(uft_y);
		if(uft_x==uft_y)return true;
		return false;
	}
};

vector<int> path[440000];
int col[440000];

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c,d;
	int x,y,z;
	scanf("%d%d%d",&n,&m,&p);
	Lca la(2*n);
	union_find_tree ua(2*n);
	queue<P> q1;
	memset(col,-1,sizeof(col));
	for(i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		a--,b--;
		path[a].push_back(n+i);
		path[b].push_back(n+i);
		path[n+i].push_back(a);
		path[n+i].push_back(b);
		la.connect(a,n+i);
		la.connect(b,n+i);
	}
	la.reload();
	for(i=0;i<p;i++){
		scanf("%d",&a);
		a--;
		q1.push(make_pair(a,i));
	}
	
	for(j=0;j<=m;j++){
		k=q1.size();
		while(k--){
			a=q1.front().first,b=q1.front().second,q1.pop();
			if(col[a]==b)continue;
			if(col[a]!=-1){
				ua.connect(b,col[a]);
				continue;
			}
			col[a]=b;
			for(auto to:path[a]){
				q1.push(make_pair(to,b));
			}
		}
	}
	scanf("%d",&p);
	for(i=0;i<p;i++){
		scanf("%d%d",&a,&b);
		a--,b--;
		c=la.lca(a,b);
		x=la.get_depth(a)-la.get_depth(c);
		y=la.get_depth(b)-la.get_depth(c);
		if(x+y<=2*m){
			printf("YES\n");
			continue;
		}
		if(x>=m)c=la.check_parent(a,m);
		else c=la.check_parent(b,x+y-m);
		if(y>=m)d=la.check_parent(b,m);
		else d=la.check_parent(a,x+y-m);
		c=col[c],d=col[d];
		if(c==-1 || d==-1 || !ua.check_connect(c,d)){
			printf("NO\n");
		}else printf("YES\n");
	}
}