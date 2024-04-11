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

typedef tuple<int,int,int> T;
string sa;
int num[200][30];
vector<T> path[200];
int s[200];
bool used[200];

void check(int a,int b){
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	int n=b-a+1;
	int i,j,k;
	int x,y;
	string sb;
	memset(num,0,sizeof(num));
	for(i=0;i<n*(n+1)/2;i++){
		cin>>sb;
		x=sb.size()-1;
		for(j=0;j<=x;j++){
			y=(int)sb[j]-(int)'a';
			num[x][y]++;
		}
	}
	for(i=n;i>=0;i--){
		for(j=0;j<30;j++){
			num[i+1][j]-=num[i][j];
		}
	}
	for(i=0;i<=(n-1)/2;i++){
		x=-1;
		for(j=0;j<30;j++){
			if(i<(n-1)/2)num[i][j]-=num[i+1][j];
			if(num[i][j]==2)s[a+i]=j,s[b-i]=j;
			if(num[i][j]==1){
				if(x==-1)x=j;
				else y=j;
			}
		}
		if(i==(n-1)/2 && n%2==1){
			s[a+i]=x;
			break;
		}
		if(x!=-1){
			path[a+i].push_back(make_tuple(b-i,x,y));
			path[b-i].push_back(make_tuple(a+i,x,y));
		}
	}
	
}

void comp2(int pos,int p=-1){
	if(used[pos])return;
	if(s[pos]==-1)s[pos]=p;
	used[pos]=true;
	int a,b,c;
	for(auto node:path[pos]){
		tie(a,b,c)=node;
		comp2(a,b+c-s[pos]);		
	}
}

void comp(int n){
	int i;
	for(i=0;i<n;i++){
		if(s[i]!=-1)comp2(i);
	}
	sa.clear();
	char ca;
	for(i=0;i<n;i++){
		ca=(char)((int)'a'+s[i]);
		sa+=ca;
	}
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	char ca;
	cin>>n;
	if(n<=3){
		for(i=0;i<n;i++){
			cout<<"? "<<i+1<<" "<<i+1<<endl;
			cin>>ca;
			sa+=ca;
		}
		cout<<"! "<<sa<<endl;
		return 0;
	}
	memset(s,-1,sizeof(s));
	if(n%2==0){
		check(0,n-1);
		check(0,n/2);
		check(n/2,n-1);
	}else{
		check(0,n-1);
		check(0,n/2);
		check(n/2+1,n-1);
	}
	comp(n);
	cout<<"! "<<sa<<endl;
}