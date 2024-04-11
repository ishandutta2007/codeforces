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

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	string sa;
	cin>>sa;
	a=0,b=0,c=0;
	for(i=0;i<sa.size();i++){
		if('a'<=sa[i] && sa[i]<='z')a++;
		if('A'<=sa[i] && sa[i]<='Z')b++;
		if('0'<=sa[i] && sa[i]<='9')c++;
	}
	if(a==sa.size())sa[0]='A',sa[1]='0';
	else if(b==sa.size())sa[0]='a',sa[1]='0';
	else if(c==sa.size())sa[0]='A',sa[1]='a';
	else if(a==0 || b==0 || c==0){
		for(i=0;i<sa.size();i++){
			if('a'<=sa[i] && sa[i]<='z' && a>1)break;
			if('A'<=sa[i] && sa[i]<='Z' && b>1)break;
			if('0'<=sa[i] && sa[i]<='9' && c>1)break;
		}
		if(a==0)sa[i]='a';
		if(b==0)sa[i]='A';
		if(c==0)sa[i]='0';
	}
	cout<<sa<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}