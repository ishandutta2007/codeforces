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

string sa,sb,sc;

int cti(char a){
	return (int)a-(int)'a';
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int tes;
	int num[50];
	cin>>tes;
	while(tes--){
		memset(num,0,sizeof(num));
		cin>>sa>>sb>>sc;
		if(sb.size()<sa.size()){
			cout<<"NO"<<endl;
			continue;
		}
		for(auto ca:sc){
			num[cti(ca)]++;
		}
		bool flag=true;
		j=0;
		for(i=0;i<sa.size();i++){
			for(;j<sb.size() && sa[i]!=sb[j];j++){
				if(num[cti(sb[j])]<=0)flag=false;
				num[cti(sb[j])]--;
			}
			if(j>=sb.size())flag=false;
			j++;
		}
		for(;j<sb.size();j++){
			if(num[cti(sb[j])]<=0)flag=false;
			num[cti(sb[j])]--;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}