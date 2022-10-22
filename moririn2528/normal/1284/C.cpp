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

LL kai[550000];

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	cin>>n>>m;
	kai[0]=1;
	for(i=1;i<=n;i++){
		kai[i]=kai[i-1]*i;
		if(kai[i]>=m)kai[i]%=m;
	}
	LL s=0;
	for(i=0;i<n;i++){
		a=(i+1)*kai[i+1];
		if(a>=m)a%=m;
		a*=kai[n-i];
		if(a>=m)a%=m;
		s+=a;
		if(s>=m)s-=m;
	}
	cout<<s<<endl;
}