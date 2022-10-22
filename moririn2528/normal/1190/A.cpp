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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

LL t[100005];
LL n,m,p,a;
LL s=0;

LL check(LL b){
	LL i;
	for(i=0;b<m;b++,i++){
		if(t[b]>a)break;
	}
	if(i==0)return b;
	a+=i,s++;
	return check(b);
}
	

int main(){
	LL i,j,k;
	LL b,c;
	cin>>n>>m>>p;
	for(i=0;i<m;i++){
		cin>>t[i];
	}
	a=0;
	for(i=0;i<m;){
		b=t[i]-a;
		b=((b-1)/p+1)*p;
		a+=b;
		i=check(i);
	}
	cout<<s<<endl;
}