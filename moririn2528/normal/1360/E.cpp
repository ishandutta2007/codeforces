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

int used[55][55];

bool solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	string sa;
	cin>>n;
	memset(used,0,sizeof(used));
	for(i=0;i<n;i++){
		cin>>sa;
		for(j=0;j<n;j++){
			if(sa[j]=='1'){
				if(i==n-1 || j==n-1)used[i][j]=2;
				else used[i][j]=1;
			}
		}
	}
	for(i=n-1;i>=0;i--){
		for(j=n-1;j>=0;j--){
			if(used[i][j]==1)return false;
			if(used[i][j]==0)continue;
			if(i>0 && used[i-1][j]==1)used[i-1][j]=2;
			if(j>0 && used[i][j-1]==1)used[i][j-1]=2;
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