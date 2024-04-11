#include<stdio.h>
#include<map>
using namespace std;
int n;
long long int res;
map<int,int> Map1;
map<int,long long int> Map2;

int top;
int in[111111];
long long int toth[111111],oo;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x,y,z;
		scanf("%d%d%d",&y,&x,&z);
		if(!Map1.count(x))
			Map1[x] = y;
		else
			Map1[x] = min(Map1[x],y);
		Map2[x] += z;
	}
	top=0;
	map<int,int>::reverse_iterator it1 = Map1.rbegin();
	map<int,long long int>::reverse_iterator it2 = Map2.rbegin();
	long long int oo = 0;
	for(; it1!=Map1.rend(); it1++,it2++){
		int outer = it1 -> first, inner = it1 -> second;
		long long int H = it2 -> second;
		while(top!=0 && in[top-1] >= outer)top--;
		if(top!=0)H += toth[top-1];
		while(top!=0 && in[top-1] >= inner)top--;
		in[top] = inner;
		toth[top++] = H;
		oo = max(oo, H);
	}
	printf("%I64d\n",oo);
	return 0;
}