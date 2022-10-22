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

bool solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<int> v1;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	if(n==1){
		if(v1[0]==m)return true;
		else return false;
	}
	for(i=0;i<n;i++){
		if(v1[i]==m)break;
	}
	if(i==n)return false;
	a=-2,b=0;
	for(i=0;i<n;i++){
		if(v1[i]>=m){
			a++;
			if(a>=0)return true;
			a=0;
		}else a--;
	}
	return false;
}

int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		if(solve())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}