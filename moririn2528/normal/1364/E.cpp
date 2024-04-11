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
	printf("! ");
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
	fflush(stdout);
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

const int A=3,B=57;

bool used[3300],used2[3300];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d;
	vector<P> v1;
	srand(time(NULL));
	cin>>n;
	for(i=0;i<B && i<n;i++){
		memset(used2,false,sizeof(used2));
		a=rand()%n;
		while(used[a])a=rand()%n;
		used[a]=true;
		used2[a]=true;
		c=(1<<11)-1;
		for(j=0;j<A && j+1<n;j++){
			b=rand()%n;
			while(used2[b])b=rand()%n;
			used2[b]=true;
			cout<<"? "<<a+1<<" "<<b+1<<endl;
			cin>>d;
			c&=d;
		}
		v1.push_back(make_pair(a,c));
	}
	b=20;
	for(i=0;i<v1.size();i++){
		for(j=i+1;j<v1.size();j++){
			a=v1[i].second&v1[j].second;
			a=__builtin_popcount(a);
			if(b>a)b=a,c=i,d=j;
		}
	}
	int index[2]={c,d};
	vector<int> v2[2];
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			if(j==v1[index[i]].first){
				v2[i].push_back(v1[index[i]].second);
				continue;
			}
			cout<<"? "<<v1[index[i]].first+1<<" "<<j+1<<endl;
			cin>>a;
			v2[i].push_back(a);
		}
		a=(1<<11)-1;
		for(j=0;j<n;j++){
			a&=v2[i][j];
		}
		v2[i][v1[index[i]].first]=a;
	}
	vector<int> vs(n,0);
	for(i=0;i<n;i++){
		vs[i]=v2[0][i]&v2[1][i];
	}
	array_show(vs);
}