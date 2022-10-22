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

LL num[220000];
map<P,int> m1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int p,q,r;
	LL s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		s+=num[i];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		a--,c--;
		P pa=make_pair(a,b);
		if(m1.find(pa)!=m1.end()){
			p=m1[pa];
			num[p]++;
			if(num[p]>0)s++;
			if(c==-1)m1.erase(pa);
		}
		if(c!=-1){
			m1[pa]=c;
			num[c]--;
			if(num[c]>=0)s--;
		}
		printf("%lld\n",s);
	}
}