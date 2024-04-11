#include<bits/stdc++.h>
using namespace std;
int n,a[200020];
bool f[200020];
int main(){
	scanf("%d",&n);
	bool neg = false;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i] >= 1)f[i] = true;else
		if(a[i] <= -1){
			f[i] = true;
			neg = !neg;
		}
	}
	if(neg){
		int id = -1;
		for(int i=1; i<=n; i++)
			if(a[i] <= -1 && (id==-1||a[i]>a[id]))
				id = i;
		f[id] = false;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++)if(f[i])cnt++;
	if(cnt == 0){
		for(int i=1; i<=n; i++)if(a[i] == 0){
			f[i] = true;
			break;
		}
	}
	int id = -1, id2 = -1;
	for(int i=1; i<=n; i++){
		if(f[i])id = i;else
			id2 = i;
	}
	for(int i=1; i<=n; i++){
		if(f[i]){
			if(id != i)
				printf("1 %d %d\n",i,id);
		}else{
			if(id2 != i)
				printf("1 %d %d\n",i,id2);
			else
				printf("2 %d\n",id2);
		}
	}
	return 0;
}