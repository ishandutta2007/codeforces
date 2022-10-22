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

queue<int> q1[110000];
int bef[110000];

const int N=1e5+7;
int seg_N;
vector<int> vs[N*4];

void seg_init(int seg_n){
	int seg_i;
	for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
	seg_N=(1<<seg_i)-1;
	for(int seg_i=0;seg_i<seg_n;seg_i++){
		vs[seg_N+seg_i].push_back(bef[seg_i]);
	}
	for(int seg_i=seg_N-1;seg_i>=0;seg_i--){
		vs[seg_i]=vs[2*seg_i+1];
		if(!vs[2*seg_i+2].empty())vs[seg_i].insert(vs[seg_i].end(),vs[2*seg_i+2].begin(),vs[2*seg_i+2].end());
		sort(vs[seg_i].begin(),vs[seg_i].end());
	}
}

int seg_search(int seg_a,int seg_b,int seg_r=0,int seg_l=seg_N+1,int seg_x=0){//[a,b) search
	if(seg_a<=seg_r && seg_l<=seg_b){
		return distance(vs[seg_x].begin(),lower_bound(vs[seg_x].begin(),vs[seg_x].end(),seg_a));
	}
	int seg_m=(seg_r+seg_l)/2;
	if(seg_b<=seg_m)return seg_search(seg_a,seg_b,seg_r,seg_m,2*seg_x+1);
	if(seg_m<=seg_a)return seg_search(seg_a,seg_b,seg_m,seg_l,2*seg_x+2);
	return seg_search(seg_a,seg_b,seg_r,seg_m,2*seg_x+1)+seg_search(seg_a,seg_b,seg_m,seg_l,2*seg_x+2);
}


int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		a--;
		q1[a].push(i);
		if(q1[a].size()>m){
			b=q1[a].front(),q1[a].pop();
		}else b=-1;
		bef[i]=b;
	}
	seg_init(n);
	int s=0;
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a=(a+s)%n+1;
		b=(b+s)%n+1;
		if(a>b)swap(a,b);
		a--;
		s=seg_search(a,b);
		cout<<s<<endl;
	}
	//array_show(bef,n);
}