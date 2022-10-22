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

const int N=200005;
queue<int> uft_q1;
int uft_parent[N];
int uft_num[N];
bool roop[N];

int uft_check_parent(int uft_x){
	if(uft_parent[uft_x]!=-1){
		uft_q1.push(uft_x);
		return uft_check_parent(uft_parent[uft_x]);
	}
	int uft_a;
	while(!uft_q1.empty()){
		uft_a=uft_q1.front(),uft_q1.pop();
		uft_parent[uft_a]=uft_x;
	}
	return uft_x;
}

bool uft_connect(int uft_x,int uft_y){
	uft_x=uft_check_parent(uft_x),uft_y=uft_check_parent(uft_y);
	if(uft_x==uft_y){
		if(roop[uft_x])return true;
		roop[uft_x]=true;
		return false;
	}
	if(roop[uft_x] && roop[uft_y])return true;
	if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
	uft_parent[uft_x]=uft_y;
	uft_num[uft_y]+=uft_num[uft_x];
	if(roop[uft_x])roop[uft_y]=true;
	return false;
}

vector<tuple<int,int,int> > v1;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n>>m;
	memset(uft_parent,-1,sizeof(uft_parent));
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		v1.push_back(make_tuple(c,a,b));
	}
	sort(v1.rbegin(),v1.rend());
	for(auto node:v1){
		tie(c,a,b)=node;
		if(!uft_connect(a,b))s+=c;
	}
	cout<<s<<endl;
}