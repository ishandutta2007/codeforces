#include<cstdio>
#include<map>
using namespace std;
const int N=200002;
int n,k,q[N],s,e,a;
map<int,bool>in;
int main(){
	scanf("%d%d",&n,&k);
	e=-1;
	while(n--){
		scanf("%d",&a);
		if(in[a]==0){
			q[++e]=a;
			in[a]=1;
			if(e-s+1>k)
				in[q[s]]=0,s++;
		}
	}
	printf("%d\n",e-s+1);
	while(s<=e)
		printf("%d ",q[e--]);
}