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
int n,m;
string sa[20];
string ss;

bool check(){
	int i,j;
	int a;
	for(i=0;i<n;i++){
		a=0;
		for(j=0;j<m;j++){
			if(ss[j]!=sa[i][j])a++;
		}
		if(a>=2)return false;
	}
	return true;
}

void solve(){
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>sa[i];
	}
	if(n==1){
		cout<<sa[0]<<endl;
		return;
	}
	for(i=0;i<m;i++){
		k=n-1;
		for(j=1;j<n;j++){
			if(sa[j][i]==sa[j-1][i])k--;
		}
		if(k==0)continue;
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(sa[k][i]!=sa[j][i])break;
			}
			ss=sa[k];
			ss[i]=sa[j][i];
			if(check()){
				cout<<ss<<endl;
				return;
			}
		}
		cout<<-1<<endl;
		return;
	}
	cout<<sa[0]<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}