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

int bef[210000][30];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	string sa;
	cin>>sa;
	n=sa.size();
	memset(bef,-1,sizeof(bef));
	for(i=0;i<n;i++){
		for(j=0;j<30;j++){
			bef[i+1][j]=bef[i][j];
		}
		a=(int)sa[i]-(int)'a';
		bef[i+1][a]=i;
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		if(a==b || sa[a]!=sa[b]){
			cout<<"Yes"<<endl;
			continue;
		}
		c=0;
		for(j=0;j<26;j++){
			if(a<=bef[b+1][j])c++;
		}
		if(c>=3)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}