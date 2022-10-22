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

LL su[300005];
LL suma;
vector<LL> v1;
LL rui[300005];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n;
	rui[0]=1;
	for(i=1;i<=n;i++){
		rui[i]=rui[i-1]*2;
		if(rui[i]>=MAX)rui[i]%=MAX;
	}
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		su[i+1]=su[i]+v1[i];
		suma+=v1[i];
	}
	for(i=1;i<n;i++){
		a=suma-su[n-i]-su[i];
		if(a>=MAX)a%=MAX;
		a*=rui[n-i-1];
		if(a>=MAX)a%=MAX;
		s+=a;
		if(s>=MAX)s-=MAX;
	}
	cout<<s<<endl;
}