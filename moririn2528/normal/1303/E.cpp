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
#include<bitset>
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

const int N=500;
bitset<N> ba[N],bb[30],bc;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int tes;
	string sa,sb;
	cin>>tes;
	while(tes--){
		cin>>sa>>sb;
		n=sa.size(),m=sb.size();
		bool flag=false;
		for(j=0;j<26;j++){
			bb[j].reset();
		}
		for(k=0;k<m;k++){
			j=(int)sb[k]-(int)'a';
			bb[j][k+1]=1;
		}
		for(i=0;i<m;i++){
			for(j=0;j<N;j++){
				ba[j].reset();
			}
			ba[0][0]=1;
			for(j=0;j<n;j++){
				for(k=i;k>=0;k--){
					if(sa[j]==sb[k])ba[k+1]|=ba[k];
					bc=ba[k]<<1;
					a=(int)sa[j]-(int)'a';
					bc&=bb[a];
					ba[k]|=bc;
				}
			}
			/*
			for(j=0;j<=n;j++){
				cout<<ba[j]<<endl;
			}
			cout<<endl;
			*/
			for(j=0;j<26;j++){
				bb[j]>>=1;
			}
			if(ba[i][m-i])flag=true;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}