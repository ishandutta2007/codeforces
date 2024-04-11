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

bool used[20];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		a=0;
		for(j=0;j<m;j++){
			cin>>b;
			a<<=1;
			a+=b;
		}
		used[a]=true;
	}
	for(i=0;i<(1<<m);i++){
		for(j=0;j<m;j++){
			if(i&(1<<j) && used[i-(1<<j)])used[i]=true;
		}
	}
	bool flag=false;
	for(i=0;i<(1<<m);i++){
		if(used[i] && used[(1<<m)-1-i])flag=true;
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}