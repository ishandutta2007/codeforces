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

string sa,sb;
int num[210000][30];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	cin>>sa;
	cin>>m;
	for(i=0;i<n;i++){
		for(j=0;j<26;j++){
			num[i+1][j]=num[i][j];
		}
		num[i+1][(int)sa[i]-(int)'a']++;
	}
	int t[30];
	for(i=0;i<m;i++){
		memset(t,0,sizeof(t));
		cin>>sa;
		for(j=0;j<sa.size();j++){
			t[(int)sa[j]-(int)'a']++;
		}
		int z[3]={0,n+1};
		while(z[1]-z[0]>1){
			z[2]=(z[0]+z[1])/2;
			for(j=0;j<26;j++){
				if(t[j]>num[z[2]][j])break;
			}
			if(j<26)z[0]=z[2];
			else z[1]=z[2];
		}
		cout<<z[1]<<endl;
	}
}