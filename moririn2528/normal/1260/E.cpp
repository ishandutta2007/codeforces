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

vector<LL> v1;
priority_queue<LL,vector<LL>,greater<LL> > q1;

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	if(v1.back()==-1){
		cout<<0<<endl;
		return 0;
	}
	s=v1.back();
	a=n/2,b=0,i=n-2;
	while(b==0){
		for(;i>=a-1;i--){
			q1.push(v1[i]);
			b=min(b,v1[i]);
		}
		if(b==-1)break;
		s+=q1.top(),q1.pop();
		a>>=1;
	}
	cout<<s<<endl;
}