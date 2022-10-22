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
typedef pair<LL,LL> P;
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

LL s[110000];

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	vector<P> v1;
	priority_queue<LL,vector<LL>,greater<LL>> q1,q3;
	queue<LL> q2;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
	}
	sort(v1.begin(),v1.end());
	a=0;
	for(i=0,j=0;i<n;i++){
		if(!q2.empty()){
			b=q2.front(),q2.pop();
			s[b]=a+m;
			a+=m;
		}else if(q1.empty()){
			s[v1[j].second]=v1[j].first+m;
			a=v1[j].first+m,b=v1[j].second;
			j++;
		}else{
			b=q1.top(),q1.pop();
			s[b]=a+m;
			a+=m;
		}
		q3.push(b);
		for(;j<n;j++){
			if(v1[j].first>a)break;
			if(!q3.empty() && q3.top()<v1[j].second)q1.push(v1[j].second);
			else{
				q2.push(v1[j].second);
				q3.push(v1[j].second);
			}
		}
		while(!q3.empty()){
			c=q3.top();
			if(s[c])q3.pop();
			else break;
		}
		if(!q1.empty() && !q3.empty() && q1.top()<q3.top()){
			q3.push(q1.top()),q2.push(q1.top());
			q1.pop();
		}
	}
	array_show(s,n);
}