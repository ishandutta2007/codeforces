#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l,r,chk[11];
int f(int a){
	for(int i=0;i<=9;i++) chk[i]=0;
	while(a){
		if(chk[a%10]) return 0;
		chk[a%10]++;
		a/=10;
	}
	return 1;
}
int main(){
    scanf("%d %d",&l,&r);
    for(int i=l;i<=r;i++) if(f(i)) return !printf("%d",i);
    printf("-1");
}