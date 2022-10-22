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

char ca[105][105];

char ci(int a){
	if(a<26)return (char)((int)'A'+a);
	a-=26;
	if(a<26)return (char)((int)'a'+a);
	a-=26;
	return (char)((int)'0'+a);
}

int main(){
	int n,m,t,p;
	int i,j,k;
	int a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>m>>p;
		for(i=0;i<n;i++){
			cin>>ca[i];
		}
		a=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(ca[i][j]=='R')a++;
			}
		}
		b=0,c=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(i%2==0)k=j;
				else k=m-j-1;
				if(ca[i][k]=='R')b++;
				ca[i][k]=ci(c);
				if((c<a%p && b==a/p+1) ||(c>=a%p && b==a/p))b=0,c++;
				if(c>=p)c=p-1;
			}
			cout<<ca[i]<<endl;
		}
	}
}