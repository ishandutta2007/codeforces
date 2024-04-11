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
		cin>>n>>m;
		vector<int> v1(2*n,-1),v2;
		for(i=0;i<m;i++){
			cin>>a>>b;
			a--,b--;
			v1[a]=b,v1[b]=a;
		}
		int s=0;
		for(i=0;i<2*n;i++){
			if(v1[i]<=i)continue;
			a=0;
			for(j=i+1;j<v1[i];j++){
				if(v1[j]==-1)a++;
				else if(v1[j]<i || v1[i]<v1[j])s++;
			}
			s+=2*min(a,2*(n-m)-a);
		}
		s/=2;
		s+=(n-m)*(n-m-1)/2;
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