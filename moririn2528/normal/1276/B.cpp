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

vector<int> path[220005];
bool used[220000];

void check(int p,int q){
	if(p==q)return;
	if(used[p])return ;
	used[p]=true;
	for(auto to:path[p])check(to,q);
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	int p,q;
	int tes;
	cin>>tes;
	while(tes--){
		cin>>n>>m;
		cin>>p>>q;
		p--,q--;
		for(i=0;i<n;i++)path[i].clear();
		for(i=0;i<m;i++){
			cin>>a>>b;
			a--,b--;
			path[a].push_back(b);
			path[b].push_back(a);
		}
		memset(used,false,sizeof(bool)*n);
		check(p,q);
		a=0;
		for(i=0;i<n;i++){
			if(!used[i])a++;
		}
		memset(used,false,sizeof(bool)*n);
		check(q,p);
		b=0;
		for(i=0;i<n;i++){
			if(!used[i])b++;
		}
		a--,b--;
		a*=b;
		cout<<a<<endl;
	}
}