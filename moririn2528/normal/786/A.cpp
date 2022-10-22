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

int s[2][10005];
bool used[2][10005];
int cnt[2][10005];
vector<int> v1[2];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(j=0;j<2;j++){
		cin>>m;
		for(i=0;i<m;i++){
			cin>>a;
			v1[j].push_back(a);
		}
	}
	s[0][0]=-1,s[1][0]=-1;
	for(j=0,k=0;j<2*n*n;j++,k--){
		for(i=0;i<2;i++){
			if(k<0)k+=n;
			if(used[i][k])continue;
			if(cnt[i][k]==v1[i].size())s[i][k]=-1;
			if(s[i][k]==0)continue;
			used[i][k]=true;
			if(s[i][k]==1){
				for(auto to:v1[1-i]){
					a=k-to;
					if(a<0)a+=n;
					cnt[1-i][a]++;
				}
			}
			if(s[i][k]==-1){
				for(auto to:v1[1-i]){
					a=k-to;
					if(a<0)a+=n;
					s[1-i][a]=1;
				}
			}
		}
	}
	for(i=0;i<2;i++){
		for(j=1;j<n;j++){
			if(s[i][j]==-1)cout<<"Lose";
			if(s[i][j]==0)cout<<"Loop";
			if(s[i][j]==1)cout<<"Win";
			if(j!=n-1)cout<<" ";
		}
		cout<<endl;
	}
}