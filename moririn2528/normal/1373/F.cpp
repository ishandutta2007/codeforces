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

void init(){
	
}

bool solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<int> v1,v2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		v1.push_back(a);
	}
	for(i=0;i<n;i++){
		scanf("%d",&a);
		v2.push_back(a);
	}
	a=min(v1[0],v2[0]);
	v2[0]-=a;
	v2[n-1]-=v1[0]-a;
	if(v2[n-1]<0)return false;
	for(i=1;i<n;i++){
		b=min(v1[i],v2[i-1]);
		v1[i]-=b,v2[i-1]-=b;
		if(v2[i]<v1[i]){
			if(i==n-1)return false;
			b=v1[i]-v2[i];
			if(a<b || v2[n-1]<b)return false;
			a-=b,v2[n-1]-=b;
			a=min(a,v2[i]);
			v2[i]=0;
		}else{
			a=min(a,v1[i]);
			v2[i]-=v1[i];
		}
	}
	return true;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		if(solve())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}