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

string sa,sb;

int change_ci(char ca,char cb,char cc){
	int a=(int)ca-(int)'A',b=(int)cb-(int)'A',c=(int)cc-(int)'A';
	a=a*30*30+b*30+c;
	return a;
}

void change_ic(int a,string &ss){
	int b,c;
	c=a%30,a/=30;
	b=a%30,a/=30;
	ss[0]=(char)((int)'A'+a);
	ss[1]=(char)((int)'A'+b);
	ss[2]=(char)((int)'A'+c);
	ss[3]='\0';
}

const int N=300005;
int t[10005][2];
int sel[1005];
int num[N][2];
vector<int> v1[N];
queue<int> q1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	bool flag=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>sa>>sb;
		t[i][0]=change_ci(sa[0],sa[1],sa[2]);
		t[i][1]=change_ci(sa[0],sa[1],sb[0]);
		v1[t[i][0]].push_back(i);
		num[t[i][0]][0]++;
	}
	for(i=0;i<N;i++){
		if(num[i][0]>1)q1.push(i);
	}
	while(!q1.empty()){
		a=q1.front(),q1.pop();
		if(num[a][1]>1){
			flag=false;
			break;
		}
		if(num[a][0]+num[a][1]<=1)continue;
		num[a][0]=0;
		for(auto node:v1[a]){
			b=t[node][1];
			sel[node]=1;
			num[b][1]++;
			if(num[b][0]+num[b][1]>1)q1.push(b);
		}
	}
	if(flag)cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl;
		return 0;
	}
	sa.resize(3);
	for(i=0;i<n;i++){
		a=sel[i];
		change_ic(t[i][a],sa);
		cout<<sa<<endl;
	}
}