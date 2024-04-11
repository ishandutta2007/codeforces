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

LL gcd(LL a,LL b){
	if(a<b)return gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
}



int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		c=gcd(a,b);
		a/=c,b/=c;
		a*=b;
		if(c%a!=0){
			printf("No\n");
			continue;
		}
		b=cbrt(c/a);
		b=b*b*b;
		if(c==a*b)printf("Yes\n");
		else printf("No\n");
	}
}