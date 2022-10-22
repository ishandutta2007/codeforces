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

string sa,sb;

int main(){
	int n,m;
	int i,j;
	int a,b,c;
	bool flag=false;
	cin>>n>>m;
	cin>>sa;
	sb=sa;
	for(i=m;i<n;i++){
		sb[i]=sb[i-m];
	}
	for(i=0;i<n;i++){
		if((int)sa[i]<(int)sb[i]){
			cout<<sb.size()<<endl;
			cout<<sb<<endl;
			return 0;
		}
		if((int)sa[i]>(int)sb[i])break;
	}
	if(i==n){
		cout<<sb.size()<<endl;
		cout<<sb<<endl;
	}else{
		for(i=m-1;i>=0;i--){
			c=(int)sb[i]-(int)'0';
			if(c<9){
				sb[i]=(char)(c+1+(int)'0');
				break;
			}else sb[i]='0';
		}
		for(i=m;i<n;i++){
			sb[i]=sb[i-m];
		}
		cout<<sb.size()<<endl;
		cout<<sb<<endl;
	}
}