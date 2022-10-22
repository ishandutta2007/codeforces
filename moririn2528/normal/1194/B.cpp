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

char ca[55555];
string sa;
vector<string> v1;
vector<int> va,vb;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int tes;
	cin>>tes;
	while(tes--){
		scanf("%d%d",&n,&m);
		v1.clear();
		va.clear();
		vb.clear();
		for(i=0;i<n;i++){
			scanf("%s",ca);
			sa=ca;
			v1.push_back(sa);
		}
		a=m;
		for(i=0;i<n;i++){
			b=0;
			for(j=0;j<m;j++){
				if(v1[i][j]=='.')b++;
			}
			if(a>b){
				va.clear();
				a=b,va.push_back(i);
			}else if(a==b)va.push_back(i);
		}
		c=n;
		for(i=0;i<m;i++){
			b=0;
			for(j=0;j<n;j++){
				if(v1[j][i]=='.')b++;
			}
			if(c>b){
				vb.clear();
				c=b,vb.push_back(i);
			}else if(c==b)vb.push_back(i);
		}
		bool flag=true;
		for(auto ti:va){
			for(auto tj:vb){
				if(flag && v1[ti][tj]=='.'){
					cout<<a+c-1<<endl;
					flag=false;
				}
			}
		}
		if(flag)cout<<a+c<<endl;
	}
}