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

string sa;
char se[1000005];
int num[1000005];
priority_queue<P> q1;
queue<P> q2;
vector<int> vs;

void reload(int pos,int a){
	num[pos+1]=a;
	q1.push(make_pair(a,pos+1));
	if(a<0)q2.push(make_pair(a,pos+1));
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int p,q;
	cin>>n;
	cin>>sa;
	int pos=0;
	a=0,b=0;
	for(i=0;i<n;i++){
		if(sa[i]=='R'){
			pos++;
			if(se[pos]=='(')a++,b++;
			if(se[pos]==')')a--,b--;
			reload(pos,a);
		}else if(sa[i]=='L'){
			if(pos>0){
				reload(pos,b);
				if(se[pos]=='(')a--,b--;
				if(se[pos]==')')a++,b++;
				pos--;
			}
		}else {
			if(se[pos]=='(')a--;
			if(se[pos]==')')a++;
			se[pos]=sa[i];
			if(sa[i]=='(')a++;
			if(sa[i]==')')a--;
			if(num[pos+1]!=a)reload(pos,a);
		}
		if(a!=b){
			vs.push_back(-1);
			continue;
		}
		bool flag=true;
		while(!q2.empty()){
			p=q2.front().first,q=q2.front().second;
			if(num[q]==p){
				flag=false;
				break;
			}
			q2.pop();
		}
		if(!flag){
			vs.push_back(-1);
			continue;
		}
		while(!q1.empty()){
			p=q1.top().first,q=q1.top().second;
			if(num[q]==p)break;
			q1.pop();
		}
		if(q1.empty())p=0;
		vs.push_back(p);
	}
	array_show(vs);
}