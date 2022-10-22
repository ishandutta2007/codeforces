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


vector<int> v1[1005];
int s[1005][1005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int x,y;
	cin>>n;
	v1[0].push_back(n+1);
	for(i=0;i<n;i++){
		cin>>a;
		b=n+1-a,c=0;
		for(j=0;j<v1[i].size();c+=v1[i][j++]){
			if(v1[i][j]==1){
				v1[i+1].push_back(1);
				if(a>b)a--,s[c][i]=1;
				else b--,s[c][i]=0;
				continue;
			}
			if(a<v1[i][j]){
				v1[i+1].push_back(a),v1[i+1].push_back(v1[i][j]-a);
				for(j++;j<v1[i].size();j++)v1[i+1].push_back(v1[i][j]);
				for(k=c;k<=n;k++){
					if(k<c+a)s[k][i]=1;
					else s[k][i]=0;
				}
				break;
			}
			if(b<v1[i][j]){
				v1[i+1].push_back(b),v1[i+1].push_back(v1[i][j]-b);
				for(j++;j<v1[i].size();j++)v1[i+1].push_back(v1[i][j]);
				for(k=c;k<=n;k++){
					if(k<c+b)s[k][i]=0;
					else s[k][i]=1;
				}
				break;
			}
			x=v1[i][j]/2,y=v1[i][j]-x;
			if(a>b)swap(x,y);
			a-=x,b-=y;
			v1[i+1].push_back(x),v1[i+1].push_back(y);
			for(k=c;k<c+v1[i][j];k++){
				if(k<c+x)s[k][i]=1;
				else s[k][i]=0;
			}
		}
	}
	printf("%d\n",n+1);
	for(i=0;i<n+1;i++){
		for(j=0;j<n;j++){
			printf("%d",s[i][j]);
		}
		printf("\n");
	}
}