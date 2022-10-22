#include<iostream>
using namespace std;
int main(){
	int a,b,f,k,g;
	int i,j;
	int s=0;
	cin>>a>>b>>f>>k;
	g=b;
	for(i=0;i<k;i++){
		if(i%2==0)j=f*2;
		else j=(a-f)*2;
		if(i==0)j/=2;
		g-=j;
		if(g<0){
			s=-1;
			break;
		}
		if(i%2==0)j=(a-f)*2;
		else j=f*2;
		if(i==k-1)j/=2;
		if(g<j)s++,g=b;
		if(g-j<0)s=-1;
	}
	cout<<s<<endl;
	return 0;
}