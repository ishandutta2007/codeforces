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

int main(){
	int s[105];
	int n;
	int i,j,k;
	char ca[105];
	bool al[30];
	int a,b,c;
	memset(s,true,sizeof(s));
	cin>>n;
	for(i=0;i<n;i++){
		memset(al,false,sizeof(al));
		cin>>ca;
		for(j=0;j<strlen(ca);j++){
			a=(int)ca[j]-(int)'a';
			if(al[a]){
				s[i]=false;
				break;
			}
			al[a]=true;
		}
		for(a=0,j=0;j<26;j++){
			if(a==0 && al[j])a=1;
			if(a==1 && !al[j])a=2;
			if(a==2 && al[j]){
				s[i]=false;
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		print_Yes_No(s[i]);
	}
}