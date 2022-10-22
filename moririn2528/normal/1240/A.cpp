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
#include<set>
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

LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

void solve(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL t[3][2];
	LL s;
	cin>>n;
	vector<LL> v1;
	for(i=0;i<n;i++){
		cin>>a;
		a/=100;
		v1.push_back(a);
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			cin>>t[i][j];
		}
	}
	if(t[0][0]<t[1][0]){
		swap(t[0][0],t[1][0]);
		swap(t[0][1],t[1][1]);
	}
	cin>>m;
	t[2][0]=t[0][0]+t[1][0];
	t[2][1]=t[0][1]*t[1][1]/gcd(t[0][1],t[1][1]);
	sort(v1.rbegin(),v1.rend());
	LL z[3]={-1,n+1};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		a=z[2]/t[0][1];
		b=z[2]/t[1][1];
		c=z[2]/t[2][1];
		a-=c,b-=c;
		s=0;
		for(i=0;i<z[2];i++){
			if(i<c)s+=t[2][0]*v1[i];
			else if(i<c+a)s+=t[0][0]*v1[i];
			else if(i<c+a+b)s+=t[1][0]*v1[i];
		}
		if(s>=m)z[1]=z[2];
		else z[0]=z[2];
	}
	if(z[1]>n)z[1]=-1;
	cout<<z[1]<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}