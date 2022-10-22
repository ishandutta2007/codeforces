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

vector<pair<LL,int> > v1,v2;
vector<int> vs;

int main(){
	int n,m;
	LL i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=3;i<=n;i++){
		cout<<1<<" "<<1<<" "<<2<<" "<<i<<endl;
		cin>>a;
		cout<<2<<" "<<1<<" "<<2<<" "<<i<<endl;
		cin>>b;
		if(b==-1)v1.push_back(make_pair(a,i));
		else v2.push_back(make_pair(a,i));
	}
	if(!v1.empty()){
		sort(v1.rbegin(),v1.rend());
		c=2*v1[0].first+1;
		for(i=1;i<v1.size();i++){
			cout<<2<<" "<<1<<" "<<v1[0].second<<" "<<v1[i].second<<endl;
			cin>>b;
			if(b==1)v1[i].first=c-v1[i].first;
		}
		sort(v1.begin(),v1.end());
	}
	if(!v2.empty()){
		sort(v2.rbegin(),v2.rend());
		c=2*v2[0].first+1;
		for(i=1;i<v2.size();i++){
			cout<<2<<" "<<1<<" "<<v2[0].second<<" "<<v2[i].second<<endl;
			cin>>b;
			if(b==1)v2[i].first=c-v2[i].first;
		}
		sort(v2.begin(),v2.end());
	}
	vs.push_back(0);
	vs.push_back(1);
	for(auto node:v1){
		vs.push_back(node.second);
	}
	vs.push_back(2);
	for(auto node:v2){
		vs.push_back(node.second);
	}
	array_show(vs);
}