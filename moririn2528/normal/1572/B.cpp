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
		os<<v1[i]+1;
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

	vector<int> vs,v1;
	
	void calc(int l, int r){
		if(l+1==r)return;
		int i;
		for(i=l;i+2<r;i+=2){
			vs.push_back(i);
		}
		for(i=r-5;l<=i;i-=2){
			vs.push_back(i);
		}
	}

	void solve(){
		int n,m;
		int i,j,k;
		int a,b,c;
		cin>>n;
		v1.resize(n);
		cin>>v1;
		vs.clear();
		a=0;
		for(i=0;i<n;i++){
			a^=v1[i];
		}
		if(a){
			cout<<"NO"<<endl;
			return;
		}
		if(n%2==1)calc(0,n);
		else{
			a=0;
			for(i=0;i<n;i++){
				a^=v1[i];
				if(a==0 && i%2==0){
					calc(0,i+1);calc(i+1,n);
					break;
				}
			}
			if(i==n){
				cout<<"NO"<<endl;
				return;
			}
		}
		cout<<"YES"<<endl;
		cout<<vs.size()<<endl;
		cout<<vs<<endl;
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