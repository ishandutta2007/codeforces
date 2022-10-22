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

priority_queue<P> q1;
int t[300005];
int s[300005];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=0;i<=m && i<n;i++){
		q1.push(make_pair(t[i],i));
	}
	LL p=0;
	for(i=0;i<n;i++){
		a=q1.top().first,b=q1.top().second,q1.pop();
		p+=a*(m+i-b);
		s[b]=m+i+1;
		a=m+i+1;
		if(a<n)q1.push(make_pair(t[a],a));
	}
	cout<<p<<endl;
	array_show(s,n);
}