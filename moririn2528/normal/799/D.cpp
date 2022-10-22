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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const LL INF=1<<30;
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

map<P,P> m1;
vector<LL> v1;

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	LL x,y;
	cin>>x>>y;
	cin>>a>>b;
	if(x>y)swap(x,y);
	if(a>b)swap(a,b);
	m1[make_pair(a,b)]=make_pair(0,0);
	if(x<=a && y<=b){
		cout<<0<<endl;
		return 0;
	}
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.rbegin(),v1.rend());
	k=0;
	for(auto node:v1){
		k++;
		for(auto be:m1){
			if(be.second.second==k)continue;
			P pa=be.first;
			pa.first*=node;
			if(pa.first>pa.second)swap(pa.first,pa.second);
			pa.first=min(pa.first,INF),pa.second=min(pa.second,INF);
			if(m1.find(pa)==m1.end()){
				m1[pa]=make_pair(be.second.first+1,k);
				if(x<=pa.first && y<=pa.second){
					cout<<m1[pa].first<<endl;
					return 0;
				}
			}
			pa=be.first;
			pa.second*=node;
			if(pa.first>pa.second)swap(pa.first,pa.second);
			if(m1.find(pa)==m1.end()){
				m1[pa]=make_pair(be.second.first+1,k);
				if(x<=pa.first && y<=pa.second){
					cout<<m1[pa].first<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
}