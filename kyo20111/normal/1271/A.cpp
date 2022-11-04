#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d,e,f;
int main(){
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	printf("%d",max(min(a,d)*e + min({b,c,d-min(a,d)})*f, min(a,d-min({b,c,d}))*e + min({b,c,d})*f));
}