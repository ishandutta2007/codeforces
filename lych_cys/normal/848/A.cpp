#include<bits/stdc++.h>
#define N 100005
using namespace std;

int f[N];
int main(){
	int i,j; char ch='a';
	f[2]=1;
	for (i=3; ; i++){
		f[i]=100001;
		for (j=1; j<i; j++) f[i]=min(f[i],j*(i-j)+f[j]+f[i-j]);
		if (f[i]>100000) break;
		//if (i%1000==0) cout<<i<<endl;
		//if (i<5) cout<<i<<' '<<f[i]<<endl;
	}
	//cout<<i<<endl;
	//cout<<f[4]<<endl;
	int n; scanf("%d",&n);
	if (n==0){ puts("ab"); return 0; }
	for (; i>1; i--) while (n>=f[i]){
		//cout<<i<<' '<<f[i]<<endl;
		for (j=i; j; j--) putchar(ch);
		n-=f[i]; ch++;
		//system("pause");
	}
	puts("");
	return 0;
}