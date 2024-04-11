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
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> LP;
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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
	int n=v1.size();
	for(int i=0;i<n;i++){
		if(i)os<<" ";
		os<<v1[i];
	}
	return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	os<<p.first<<" "<<p.second;
	return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
	int n=v1.size();
	for(int i=0;i<n;i++)is>>v1[i];
	return is;
}
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
	is>>p.first>>p.second;
	return is;
}

namespace sol{

	void init(){
		
	}


	void solve(){
		int n,m;
		int i,j,k;
		int a,b,c;
		cin>>n;
		vector<char> used(n);
		vector<vector<int>> path(n);
		vector<int> dis(n,1),deg(n);
		queue<int> q1;
		for(i=0;i<n;i++){
			cin>>a;
			for(j=0;j<a;j++){
				cin>>b;
				b--;
				path[b].push_back(i);
			}
			if(a==0)q1.push(i);
			deg[i]=a;
		}
		while(!q1.empty()){
			a=q1.front();q1.pop();
			if(used[a])continue;
			used[a]=1;
			for(auto to:path[a]){
				if(to<a)dis[to]=max(dis[to],dis[a]+1);
				else dis[to]=max(dis[to],dis[a]);
				deg[to]--;
				if(deg[to]==0)q1.push(to);
			}
		}
		int s=0;
		for(i=0;i<n;i++){
			if(!used[i]){
				cout<<-1<<endl;
				return;
			}
			s=max(s,dis[i]);
		}
		cout<<s<<endl;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,i;
	sol::init();
	cin>>n;
	for(i=0;i<n;i++){
		sol::solve();
	}
}