#include<stdio.h>
int main(){
	int n,m[16],r[16];
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&m[i]);
	for(int i=0; i<n; i++)
		scanf("%d",&r[i]);
	int res=0;
	for(int run = 0; run < 720720; run++){
		bool flag=true;
		for(int i=0; i<n; i++)
			if(run % m[i] == r[i])
				flag = false;
		if(!flag)res++;
	}
	printf("%.12lf\n",res/720720.);
	return 0;
}