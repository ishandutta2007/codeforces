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

LL t[30];
string sa,sb;

int gcd(LL a,LL b){
	if(a<b)gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	cin>>n;
	a=0;
	for(i=0;i<n;i++){
		cin>>t[i];
		a+=t[i];
	}
	for(i=0;i<n;i++){
		char ca=(char)((int)'a'+i);
		for(j=0;j<t[i];j++){
			sa+=ca;
		}
	}
	if(n==1){
		cout<<t[0]<<endl;
		cout<<sa<<endl;
		return 0;
	}
	if(a%2==0){
		b=a;
		for(i=0;i<n;i++){
			if(t[i]%2==1){
				cout<<0<<endl;
				cout<<sa<<endl;
				return 0;
			}
			b=gcd(b,t[i]);
		}
		for(i=0;i<n;i++){
			c=t[i]/b;
			char ca=(char)((int)'a'+i);
			for(j=0;j<c;j++){
				sb+=ca;
			}
		}
		for(i=1;i<b;i++){
			for(j=0;j<a/b;j++){
				k=i*a/b-j-1;
				sb+=sb[k];
			}
		}
		cout<<b<<endl;
		cout<<sb<<endl;
		return 0;
	}
	c=0;
	for(i=0;i<n;i++){
		if(t[i]%2==1)c++,b=i;
		a=gcd(a,t[i]);
	}
	if(c>1){
		cout<<0<<endl;
		cout<<sa<<endl;
		return 0;
	}
	for(i=0;i<n;i++){
		char ca=(char)((int)'a'+i);
		for(j=0;j<t[i]/a/2;j++){
			sb+=ca;
		}
	}
	sb+=(char)((int)'a'+b);
	for(i=n-1;i>=0;i--){
		char ca=(char)((int)'a'+i);
		for(j=0;j<t[i]/a/2;j++){
			sb+=ca;
		}
	}
	sa.clear();
	for(i=0;i<a;i++){
		sa+=sb;
	}
	cout<<a<<endl;
	cout<<sa<<endl;
}