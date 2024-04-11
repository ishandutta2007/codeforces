#include<iostream>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n;
	int i,j,k;
	int a[30];
	bool s=false,leep=false;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<12;i++){
		leep=false,s=true;
		for(j=0;j<n;j++){
			k=(i+j)%12;
			if(a[j]!=month[k]){
				if(k==1 && !leep && a[j]==29)leep=true;
				else{
					s=false;
					break;
				}
			}
		}
		if(s)break;
	}
	if(s)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}