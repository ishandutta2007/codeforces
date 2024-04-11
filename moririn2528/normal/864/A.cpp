#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	int a[105][2];
	bool s=true;
	bool s2=true;
	int i,j,k;
	int b,c,d;
	memset(a,0,sizeof(a));
	
	cin>>n;
	for(i=0,k=0;i<n;i++){
		cin>>b;
		s2=false;
		for(j=0;j<k;j++){
			if(a[j][0]==b)a[j][1]++,s2=true;
		}
		if(!s2)a[k][0]=b,a[k][1]=1,k++;
		if(k>=3)s=false;
	}
	if(a[0][1]!=a[1][1])s=false;
	if(!s)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<a[0][0]<<" "<<a[1][0]<<endl;
	}
}