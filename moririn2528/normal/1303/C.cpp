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

bool used[30];
string sa;
vector<int> v1;

bool check(){
	int a,b,c;
	c=0;
	v1.clear();
	memset(used,false,sizeof(used));
	for(auto ca:sa){
		a=(int)ca-(int)'a';
		if(!used[a]){
			used[a]=true;
			if(c==v1.size()-1)v1.push_back(a),c++;
			else if(c==0)v1.insert(v1.begin(),a);
			else return false;
		}else{
			if(c>0 && v1[c-1]==a)c--;
			else if(c+1<v1.size() && v1[c+1]==a)c++;
			else return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	while(n--){
		cin>>sa;
		if(check()){
			cout<<"YES"<<endl;
			sa.clear();
			for(auto node:v1){
				sa+=(char)((int)'a'+node);
			}
			for(i=0;i<26;i++){
				if(used[i])continue;
				sa+=(char)((int)'a'+i);
			}
			cout<<sa<<endl;
		}else cout<<"NO"<<endl;
	}
}