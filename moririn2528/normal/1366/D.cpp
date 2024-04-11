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

int t[10000005];

int main(){
	int n,m;
	LL i,j,k;
	LL a,b,c;
	for(i=2;i<=1e7;i++){
		if(t[i])continue;
		for(j=i*i;j<=1e7;j+=i){
			if(t[j]==0)t[j]=i;
		}
	}
	cin>>n;
	vector<int> v1,v2;
	for(i=0;i<n;i++){
		cin>>a;
		if(t[a]==0){
			v1.push_back(-1),v2.push_back(-1);
			continue;
		}
		b=t[a];
		while(a%b==0)a/=b;
		if(a==1)b=-1,c=-1;
		else c=a;
		v1.push_back(b),v2.push_back(c);
	}
	array_show(v1);
	array_show(v2);
}