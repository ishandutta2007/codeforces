#include<cstdio>
int n,m,k,a,s;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	while(n--){
		scanf("%d",&a);
		if(a==1){
			if(m)
				m--;
			else
				s++;
		}
		else{
			if(k)
				k--;
			else{
				if(m)
					m--;
				else
					s++;
			}
		}
	}
	printf("%d",s);
	return 0;
}