#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char ca[3005],cs[6005];
	char cb;
	int i,j,k;
	bool differ=false;
	cin>>ca;
	for(i=0,j=0,k=0;i<strlen(ca);i++,j++){
		if(ca[i]=='a'||ca[i]=='e'||ca[i]=='i'
		||ca[i]=='o'||ca[i]=='u'){
			k=0,cs[j]=ca[i],differ=false;
			continue;
		}
		if(k>0 && ca[i-1]!=ca[i])differ=true;
		k++;
		if(k>=3 && differ){
			k=1,cs[j]=' ',j++,differ=false;
		}
		cs[j]=ca[i];
	}
	cs[j]='\0';
	cout<<cs<<endl;
	return 0;
}