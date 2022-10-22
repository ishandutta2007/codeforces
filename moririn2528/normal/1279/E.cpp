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
const LL INF=(LL)1<<60;
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
		uft_parent[uft_x]=uft_y;
		uft_num[uft_y]+=uft_num[uft_x];
		return false;
	}
};

void init(){
	
}

LL kai[100];
LL cnt[100];

void solve(){
	LL n,m;
	LL i,j,k;
	LL a,b,c,d;
	cin>>n>>m;
	
	if(cnt[n]<m){
		cout<<-1<<endl;
		return;
	}
	vector<int> v1;
	vector<int> vs(n,-1);
	union_find_tree ua(n);
	bool used[100];
	memset(used,false,sizeof(used));

	m--;
	LL p,q,r;
	p=n;
	for(i=1;i<=p;i++){
		if(i>2)a=kai[i-2];
		else a=1;
		if(a>=INF || a>=INF/cnt[p-i]+1){
			a=INF;
		}else a*=cnt[p-i];
		if(a<=m){
			m-=a;
			continue;
		}

		a=n-p;
		if(i==1){
			vs[a]=a;
			p-=i;i=0;
			continue;
		}
		if(i==2){
			vs[a]=a+1,vs[a+1]=a;
			p-=i;i=0;
			continue;
		}

		b=m/cnt[p-i],m%=cnt[p-i];
		used[a+i-1]=true;
		ua.connect(a+i-1,a);
		vs[a]=a+i-1;
		for(k=a+1;k<a+i-1;k++){
			j=a+i-2-k;
			c=b/kai[j],b%=kai[j];
			int par=ua.check_parent(k);
			for(j=a;j<a+i;j++){
				if(k==j || used[j] || par==j)continue;
				if(c==0)break;
				c--;
			}
			vs[k]=j;
			used[j]=true;
			ua.connect(j,k);
		}
		vs[a+i-1]=ua.check_parent(a+i-1);
		p-=i;i=0;
	}

	for(auto& node:vs)node++;
	array_show(vs);
}

int main(){
	LL n,i,j;
	LL a,b;
	const int N=50;
	init();
	cin>>n;
	kai[0]=1;
	for(i=1;i<=N;i++){
		if(kai[i-1]>=INF/i+1)kai[i]=INF;
		else kai[i]=kai[i-1]*i;
		if(kai[i]>=INF)kai[i]=INF;
	}
	cnt[1]=1,cnt[0]=1;
	for(i=2;i<=N;i++){
		for(j=1;j<=i;j++){
			if(j>2)a=kai[j-2];
			else a=1;
			if(a>=INF || a>=INF/cnt[i-j]+1){
				cnt[i]=INF;
				break;
			}
			cnt[i]+=cnt[i-j]*a;
			if(cnt[i]>=INF){
				cnt[i]=INF;
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		solve();
	}
}