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

void init(){
	
}

int check(int a){
	int b=0;
	while(a>0){
		b+=a%10,a/=10;
	}
	return b;
}

int memo[10][200];

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	if(m==0){
		string sa;
		while(n>9){
			n-=9;
			sa+='9';
		}
		sa+=(int)'0'+n;
		reverse(sa.begin(),sa.end());
		cout<<sa<<endl;
		return;
	}
	if(m==1){
		if(n%2==0 && n<10){
			cout<<-1<<endl;
			return;
		}
		string sa;
		if(n%2==0){
			n-=9;
			sa+='9';
		}
		a=min(n/2,8);
		if(a>0)sa+=(int)'0'+a;
		n-=a*2+1;
		while(n>0){
			a=min(n/2,9);
			n-=a*2;
			sa+=(int)'0'+a;
		}
		if(sa.empty())sa.push_back('0');
		reverse(sa.begin(),sa.end());
		cout<<sa<<endl;
		return;
	}
	a=0;
	for(i=0;i<=m;i++){
		a+=check(i);
	}
	if(memo[m][0]!=-1){
		cout<<memo[m][n]<<endl;
		return;
	}
	memo[m][0]=0;
	for(i=0;i<=1e6;i++){
		if(a<=150 && memo[m][a]==-1)memo[m][a]=i;
		a+=check(i+m+1)-check(i);
	}
	cout<<memo[m][n]<<endl;
	return;
}

int main(){
	int n,i;
	init();
	cin>>n;
	memset(memo,-1,sizeof(memo));
	for(i=0;i<n;i++){
		solve();
	}
}