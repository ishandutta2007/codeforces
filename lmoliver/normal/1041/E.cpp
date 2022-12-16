#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1111;
int n;
int a[N],b[N];
bool u[N]={false};
int l[N];
void GG(){
	puts("NO");
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]!=n)GG();
	}
	sort(a+1,a+n-1+1);
	l[n]=n;
	u[n]=true;
	int j=1;
	for(int i=1;i<=n-1;i++){
		if(a[i]<i)GG();
		if(!u[a[i]]){
			l[i]=a[i];
			u[a[i]]=true;
		}
		else{
			while(u[j]){
				j++;
			}
			l[i]=j;
			u[j]=true;
		}
	}
	puts("YES");
	for(int i=1;i<=n-1;i++){
		printf("%d %d\n",l[i],l[i+1]);
	}
	return 0;
}