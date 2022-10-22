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

int gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

void solve(){
	int n,m;
	int i,j,k;
	LL a,b,c,d;
	cin>>a>>b>>n;
	c=a*b/gcd(a,b);
	if(a<b)swap(a,b);
	LL l,r;
	for(i=0;i<n;i++){
		cin>>l>>r;
		if(a==b){
			cout<<0<<endl;
			continue;
		}
		LL s=0;
		d=c-a;
		s=(r/c-l/c+1)*d;
		s-=d-max(r%c-a+1,(LL)0);
		s-=max(l%c-a,(LL)0);
		cout<<s<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
}