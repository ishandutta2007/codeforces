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

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	int tes;
	cin>>tes;
	while(tes--){
		cin>>a>>b;
		LL z[3]={0,a};
		while(z[1]-z[0]>1){
			z[2]=(z[0]+z[1])/2;
			c=z[2]*(z[2]+1)/2;
			if(b<=c)z[1]=z[2];
			else z[0]=z[2];
		}
		b-=z[0]*(z[0]+1)/2;
		string sa;
		for(i=a;i>0;i--){
			if(i==z[1]+1 || i==b)sa.push_back('b');
			else sa.push_back('a');
		}
		cout<<sa<<endl;
	}
}