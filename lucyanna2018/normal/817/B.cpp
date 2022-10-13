#include<stdio.h>
#include<map>
using namespace std;
map<int,int> Map;
int a[111111],n;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		Map[a[i]]++;
	}
	int w = Map.begin()->second;
	if(w >= 3)
		printf("%I64d\n",1LL*w*(w-1)*(w-2)/6);
	else
	if(w == 2){
		map<int,int>::iterator it = Map.begin();
		it++;
		printf("%I64d\n",it->second * 1LL);
	}else{
		map<int,int>::iterator it = Map.begin();
		it++;
		int w = it->second;
		if(w >= 2)
			printf("%I64d\n",1LL*(w-1)*w/2);
		else{
			it++;
			printf("%I64d\n",it->second * 1LL);
		}
	}
	return 0;
}