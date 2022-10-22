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

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	m=min(m,(LL)2e9);
	LL z[3]={-1,min(n,(LL)2e9+7)};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		if(z[2]<=m)a=z[2]*(z[2]+1)/2;
		else{
			b=m+z[2];
			if(b%2==0)a=b/2;
			else a=0;
			b=(b-1)/2;
			a+=b*(b+1)-m*(m-1)/2;
		}
		if(a>=n)z[1]=z[2];
		else z[0]=z[2];
	}
	cout<<z[1]<<endl;
}