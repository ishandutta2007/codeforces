#include<cstdio>
const int N=10002;
int n;
char ch;
void read(int &a){
	a=0;
	while((ch=getchar())>47)
		a=(a*10+ch-48)%100;
}
int main(){
	read(n);
	if(n%4==0)
		printf("4");
	else
		printf("0");
}