#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int stuff[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &stuff[i]);
		stuff[i] += i;
	}
	sort(stuff, stuff+n);
	for(int i = 0; i < n; i++){
		stuff[i] -= i;
		if(stuff[i] < 0){
			printf(":(\n");
			return 0;
		}
	}
	for(int i = 0; i < n-1; i++){
		if(stuff[i] > stuff[i+1]){
			printf(":(\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", stuff[i]);
	}
	printf("\n");


}