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

typedef int bit_type;
vector<bit_type> bit_vec[11][11][4];
int bit_N=20;

bit_type bit_comp(bit_type a,bit_type b){
	return a+b;
}

void bit_init(int n){
	for(bit_N=0;bit_N<30;bit_N++){
		if(n<(1<<bit_N))break;
	}
	int i,j,k;
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			for(k=0;k<4;k++){
				bit_vec[i][j][k].assign((1<<bit_N),0);
			}
		}
	}
}

void bit_set(int pos,bit_type x,int p,int q,int r){
	bit_vec[p][q][r][pos]=bit_comp(bit_vec[p][q][r][pos],x);
	for(int i=0;i<bit_N;i++){
		if(pos&(1<<i))continue;
		pos|=(1<<i);
		bit_vec[p][q][r][pos]=bit_comp(bit_vec[p][q][r][pos],x);
	}
}

bit_type bit_search(int pos,int p,int q,int r){
	bit_type s=bit_vec[p][q][r][pos];
	for(int i=0;pos>=(1<<i);i++){
		if(pos&(1<<i))continue;
		pos-=(1<<i);
		s=bit_comp(s,bit_vec[p][q][r][pos]);
	}
	return s;
}

int char_to_int(char ca){
	if(ca=='A')return 0;
	if(ca=='T')return 1;
	if(ca=='G')return 2;
	if(ca=='C')return 3;
	return -1;
}
string sa,sb;

int main(){
	int n,m;
	int i,j,k,l;
	int a,b,c;
	char ca;

	cin>>sa;
	bit_init((int)sa.size());
	for(i=0;i<sa.size();i++){
		l=char_to_int(sa[i]);
		for(j=1;j<=10;j++){
			k=i%j;
			bit_set(i+1,1,j,k,l);
		}
	}
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(a==1){
			cin>>a;
			a--;
			l=char_to_int(sa[a]);
			for(j=1;j<=10;j++){
				k=a%j;
				bit_set(a+1,-1,j,k,l);
			}
			cin>>ca;
			sa[a]=ca;
			l=char_to_int(sa[a]);
			for(j=1;j<=10;j++){
				k=a%j;
				bit_set(a+1,1,j,k,l);
			}
		}else{
			cin>>a>>b>>sb;
			a--;
			int s=0;
			m=sb.size();
			c=m-a%m;
			for(j=0;j<sb.size();j++,c++){
				if(c>=m)c-=m;
				s+=bit_search(b,m,j,char_to_int(sb[c]));
				s-=bit_search(a,m,j,char_to_int(sb[c]));
			}
			cout<<s<<endl;
		}
	}

}