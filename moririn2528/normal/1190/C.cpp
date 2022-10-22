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

string sa;

int n,m;

bool check(string sb){
	int i;
	int a,b,c,d;
	a=-1,b=-1,c=-1,d=-1;
	for(i=0;i<sb.size();i++){
		if(sb[i]=='0'){
			if(a==-1)a=i;
			b=i;
		}else{
			if(c==-1)c=i;
			d=i;
		}
	}
	a=b-a+1,c=d-c+1;
	if(a<=m && c<=m)return false;
	return true;
}

int main(){
	int i,j,k;
	int a,b,c,d;
	cin>>n>>m;
	cin>>sa;
	a=-1,b=-1,c=-1,d=-1;
	for(i=0;i<sa.size();i++){
		if(sa[i]=='0'){
			if(a==-1)a=i;
			b=i;
		}else{
			if(c==-1)c=i;
			d=i;
		}
	}
	a=b-a+1,c=d-c+1;
	if(a<=m || c<=m){
		cout<<"tokitsukaze"<<endl;
		return 0;
	}
	if(c>=m+2 || a>=m+2){
		cout<<"once again"<<endl;
		return 0;
	}
	string sb,sc;
	sb=sa.substr(m,n-m),sc=sa.substr(0,n-m);
	if(check(sb) || check(sc))cout<<"once again"<<endl;
	else cout<<"quailty"<<endl;
}