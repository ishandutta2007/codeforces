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

map<string,int> m1,m2;
string t[100000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	string sa,sb;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>sa;
		t[i]=sa;
		m2.clear();
		for(j=0;j<9;j++){
			for(k=1;k<=9-j;k++){
				sb=sa.substr(j,k);
				a=m1[sb];
				if(a==0)m1[sb]=i+1;
				else if(a!=i+1)m1[sb]=2*n;
			}
		}
	}

	string ss;
	for(i=0;i<n;i++){
		sa=t[i];
		ss="1234567890";
		for(j=0;j<9;j++){
			for(k=1;k<=9-j;k++){
				sb=sa.substr(j,k);
				if(m1[sb]==i+1 && ss.size()>sb.size())ss=sb;
			}
		}
		cout<<ss<<endl;
	}
	
}