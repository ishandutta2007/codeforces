#include<iostream>
using namespace std;

int check(int a,int b){
	if(a%b==0)return check(a/b,b)+1;
	else return 0;
}

int main(){
	int n,m;
	int i,j,k;
	cin>>n>>m;
	long long int s=n;
	k=max(m-check(n,2),0);
	for(i=0;i<k;i++){s*=2;}
	k=max(m-check(n,5),0);
	for(i=0;i<k;i++){s*=5;}
	cout<<s<<endl;
	return 0;
}