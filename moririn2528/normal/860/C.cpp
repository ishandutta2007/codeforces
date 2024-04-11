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

string st[110000];
int t[110000];

int string_to_int(string sa){
	int s=0;
	int a;
	for(auto ca:sa){
		s*=10;
		a=(int)ca-(int)'0';
		if(a<0 || a>=10)return -1;
		if(s==0 && a==0)return -1;
		s+=a;
	}
	return s;
}

bool used[110000];
vector<string> va[2],vb[2];
vector<pair<string,string>> vs;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	string sa;
	cin>>n;
	m=0;
	for(i=0;i<n;i++){
		cin>>st[i]>>t[i];
		if(t[i]==1)m++;
	}
	b=-1;
	for(i=0;i<n;i++){
		a=string_to_int(st[i]);
		if(a<=0 || a>n)vb[t[i]].push_back(st[i]);
		else{
			used[a]=true;
			if(t[i]==0 && a<=m)va[0].push_back(st[i]);
			if(t[i]==1 && a>m)va[1].push_back(st[i]);
		}
	}
	for(i=1;i<=n;i++){
		if(!used[i]){
			b=i;
			break;
		}
	}
	if(b==-1){
		if(va[0].empty()){
			cout<<0<<endl;
			return 0;
		}
		vs.push_back(make_pair(va[0].back(),to_string(n+1)));
		a=string_to_int(va[0].back());
		used[a]=false,b=a;
		va[0].pop_back();
		vb[0].push_back(to_string(n+1));
	}
	while(1){
		if(b<=m)a=1;
		else a=0;
		if(va[a].empty())break;
		vs.push_back(make_pair(va[a].back(),to_string(b)));
		c=string_to_int(va[a].back());
		used[c]=false,used[b]=true;
		va[a].pop_back(),b=c;
	}
	for(i=1;i<=n;i++){
		if(used[i])continue;
		if(i<=m)a=1;
		else a=0;
		if(va[a].empty())continue;
		vs.push_back(make_pair(va[a].back(),to_string(i)));
		c=string_to_int(va[a].back());
		used[c]=false,used[i]=true;
		va[a].pop_back();
	}
	for(i=1;i<=n;i++){
		if(used[i])continue;
		if(i<=m)a=1;
		else a=0;
		if(vb[a].empty())continue;
		vs.push_back(make_pair(vb[a].back(),to_string(i)));
		vb[a].pop_back();
	}
	cout<<vs.size()<<endl;
	for(auto node:vs){
		cout<<"move "<<node.first<<" "<<node.second<<endl;
	}
}