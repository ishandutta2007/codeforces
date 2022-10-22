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

LL dv[100005];
LL num[100005];
LL to[100005];
LL t[100005][2];
vector<LL> v1;

void check(int a){
	if(dv[a]==0){
		v1.push_back(a);
		return;
	}
	v1.push_back(dv[a]);
	check(to[a]);
}

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	LL s=0,rs=0,ss=0;
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	for(i=2;i<1e5+3;i++){
		if(dv[i]==0){
			for(j=i*2;j<1e5+3;j+=i){
				dv[j]=i;
			}
		}else to[i]=i/dv[i];
	}
	for(i=0;i<n;i++){
		cin>>a;
		if(t[a][0]==-1){
			v1.clear();
			check(a);
			b=-1,c=0,s=1,rs=1;
			for(j=0;j<v1.size();j++){
				if(b==v1[j])c++;
				else{
					c%=m;
					for(k=0;k<c;k++){
						if(s>1e5)break;
						s*=b;
					}
					c=(m-c)%m;
					for(k=0;k<c;k++){
						if(rs>1e5)break;
						rs*=b;
					}
					b=v1[j],c=1;
				}
			}
			
			c%=m;
			for(k=0;k<c;k++){
				if(s>1e5)break;
				s*=b;
			}
			c=(m-c)%m;
			for(k=0;k<c;k++){
				if(rs>1e5)break;
				rs*=b;
			}
			//cout<<s<<" "<<rs<<endl;
			t[a][0]=s,t[a][1]=rs;
		}
		if(t[a][1]<=1e5)ss+=num[t[a][1]];
		if(t[a][0]<=1e5)num[t[a][0]]++;
	}
	cout<<ss<<endl;
}