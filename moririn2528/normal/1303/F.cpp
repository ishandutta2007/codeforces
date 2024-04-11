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

	bool exist(int uft_x){
		assert(uft_x>=0 && uft_x<uft_n);
		if(uft_parent[uft_x]==-1 && uft_num[uft_x]==0)return false;
		return true;
	}

	void put(int uft_x){
		assert(uft_x>=0 && uft_x<uft_n);
		uft_num[uft_x]=1;
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
};

int n,m,q;

int check_push(int x,int y,union_find_tree &ua){
	int i,j;
	int a,b,c;
	int sa=1;
	int pos=x*m+y;
	
	ua.put(pos);
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((i+j+4)%2==0)continue;
			a=x+i,b=y+j;
			c=a*m+b;
			if(a<0 || n<=a || b<0 || m<=b)continue;
			if(!ua.exist(c))continue;
			if(!ua.connect(pos,c))sa--;
		}
	}
	return sa;
}

vector<tuple<int,int,int> > rv[2200000];
vector<pair<int,int> > rv_init[2200000];
int color[333][333];
int s[2100000];

int main(){
	int i,j,k;
	int a,b,c;
	int bc=-1;
	cin>>n>>m>>q;
	union_find_tree ua(n*m);
	s[0]=1;
	
	for(i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		rv[color[a][b]].push_back(make_tuple(a,b,i));
		color[a][b]=c;
		if(bc!=c){
			bc=c;
			ua.init();
		}
		s[i+1]=check_push(a,b,ua);
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			rv_init[color[i][j]].push_back(make_pair(i,j));
		}
	}

	for(i=0;i<=bc;i++){
		ua.init();
		for(auto node:rv_init[i]){
			tie(a,b)=node;
			check_push(a,b,ua);
		}
		while(!rv[i].empty()){
			tie(a,b,c)=rv[i].back(),rv[i].pop_back();
			s[c+1]-=check_push(a,b,ua);
		}
	}
	for(i=0;i<q;i++){
		s[i+1]+=s[i];
	}

	for(i=0;i<q;i++){
		printf("%d\n",s[i+1]);
	}
}