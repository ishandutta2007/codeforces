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

	int ques(bool annnd,int i,int j){
		if(annnd)cout<<"and ";
		else cout<<"or ";
		cout<<i+1<<" "<<j+1<<endl;
		int s;
		cin>>s;
		return s;
	}

	void solve(){
		int n,m;
		int i,j,k;
		int a,b,c;
		cin>>n>>m;
		vector<int> vs(n);
		vector<int> va(n),vb(n);
		a=0,b=(1<<30)-1;
		for(i=1;i<n;i++){
			va[i]=ques(1,0,i);
			vb[i]=ques(0,0,i);
			a|=va[i];
			b&=vb[i];
		}
		c=ques(1,1,2);
		for(i=0;i<30;i++){
			if(~b&1<<i)continue;
			if(a&1<<i)vs[0]|=1<<i;
			else if(~c&1<<i)vs[0]|=1<<i;
		}
		for(i=1;i<n;i++){
			vs[i]=va[i]&vs[0];
			vs[i]+=vb[i]&~vs[0];
		}
		sort(vs.begin(),vs.end());
		cout<<"finish "<<vs[m-1]<<endl;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	sol::solve();
}