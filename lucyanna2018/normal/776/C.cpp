#include<stdio.h>
#include<map>
using namespace std;
int n,k;
long long int s[111111],res;
long long int ABS(long long int z){
	return z>0?z:-z;
}
map<long long int,int> Map;
long long int chk(long long int to){
	Map.clear();
	long long int ret = 0;
	for(int i=n; i>=0; i--){
		ret += Map[s[i]+to];
		Map[s[i]]++;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		s[i] = s[i-1] + x;
	}
	res = 0;
	if(k == 1){
		res += chk(1);
	}else
	if(k == -1){
		res += chk(1);
		res += chk(-1);
	}else{
		for(long long int z = 1; ABS(z) <= (long long int)(1e15); z *= k)
			res += chk(z);
	}
	printf("%I64d\n",res);
	return 0;
}