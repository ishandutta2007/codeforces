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
int t[110000];
int num[1100000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	int cnt=0;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=n-1;i>=0;i--){
		if(t[i]==m){
			cnt++;
			continue;
		}
		if(num[t[i]]<cnt)num[t[i]]++;
	}
	for(i=1;i<=1e6;i++){
		if(i==m)continue;
		if(num[i]>=cnt){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}