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

bool used[203];
int s[203];


int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	bool flag=true;
	cin>>n>>m;
	for(i=0;i<m;i++,b=a){
		cin>>a;
		if(i==0)continue;
		c=a-b;
		if(c<=0)c+=n;
		if(used[c] && s[b-1]==c)continue;
		if(used[c] || s[b-1]!=0){
			flag=false;
			break;

		}
		used[c]=true,s[b-1]=c;
	}
	for(i=0,j=1;i<n;i++){
		if(s[i]>0)continue;
		while(used[j])j++;
		s[i]=j++;
	}
	if(flag)array_show(s,n);
	else cout<<-1<<endl;
}