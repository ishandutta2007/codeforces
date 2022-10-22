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
#include<set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

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

class Zalgo{
private:
	string str;
	vector<int> pre_len;//length same to prefix
public:
	void calc_zalgo(){
		pre_len.assign(str.size(),0);
		int n=str.size();
		int i,j,k;
		pre_len[0]=str.size();
		for(i=1,j=0;i<n;){
			for(;i+j<n;j++){
				if(str[j]!=str[i+j])break;
			}
			pre_len[i]=j;
			if(j==0){
				i++;
				continue;
			}
			i++,j--;
			for(k=1;j>0 && i<n;i++,j--,k++){
				if(pre_len[k]>=j)break;
				pre_len[i]=pre_len[k];
			}
		}
	}

	void calc_zalgo(string str_temp){
		str=str_temp;
		calc_zalgo();
	}

	vector<int> calc(string sa,int n){
		str=sa;
		int N=str.size();
		calc_zalgo();
		vector<int> vs(N-n);
		int i,j;
		int a;
		for(i=0;i<=N-2*n;i++){
			if(pre_len[n+i]>=n){
				vs[i]=2;
			}else{
				a=pre_len[n+i];
				if(str[a]<str[i+n+a])vs[i]=1;
				else vs[i]=0;
			}
		}
		return vs;
	}

	vector<int> get_pre_len(){
		return pre_len;
	}
};

LL t[2200000];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL zer=0;
	string sa,sb,sc;
	cin>>sa>>sb>>sc;
	Zalgo za;
	vector<int> v1=za.calc(sb+sa,sb.size());
	vector<int> v2=za.calc(sc+sa,sc.size());
	a=-1,b=-1;
	t[1]=1;
	for(i=0;i<sa.size();i++){
		if(i+1>=sb.size()){
			a=i+1-sb.size();
			if(v1[a]==0)a--;
		}
		if(i+1>=sc.size()){
			b=i+1-sc.size();
			if(v2[b]!=1)b--;
		}
		c=t[a+1]-t[b+1];
		if(c<0)c+=MAX;
		if(sb[0]=='0'){
			c+=zer;
			if(c>=MAX)c-=MAX;
		}
		if(i+1<sa.size() && sa[i+1]=='0'){
			zer=c;
			c=0;
		}else zer=0;
		t[i+2]=t[i+1]+c;
		if(t[i+2]>=MAX)t[i+2]-=MAX;
	}
	cout<<c<<endl;
}