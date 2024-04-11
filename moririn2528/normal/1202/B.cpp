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

int t[10];
int p,q;

void check(int x,int a){
	if(x>=10)x%=10;
	if(t[x]!=0 && t[x]<=a)return;
	t[x]=a;
	check(x+p,a+1),check(x+q,a+1);
}

int st[2000005];

int main(){
	int n,m;
	int x,y;
	int i,j,k;
	int a,b,c;
	string sa,sb;
	cin>>sa;
	n=sa.size()-1;
	for(i=0;i<n;i++){
		a=(int)sa[i+1]-(int)sa[i];
		if(a<0)a+=10;
		st[i]=a;
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++)t[k]=50;
			a=0;
			p=i,q=j;
			check(0,0);
			for(k=0;k<n;k++){
				if(t[st[k]]==50)break;
				a+=t[st[k]]-1;
			}
			if(k!=n)a=-1;
			cout<<a<<(j!=9?' ':'\n');
		}
	}
}