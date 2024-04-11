#include<iostream>
#include<cstring>
using namespace std;
int main(){
	bool a[30];
	char ca[205];
	int i,j,k;
	int n;
	int s=0;
	int t;
	memset(a,false,sizeof(a));
	cin>>n;
	cin>>ca;
	for(i=0;i<n;i++){
		k=(int)ca[i]-(int)'a';
		if(0<=k && k<26)a[k]=true;
		else{
			for(j=0,t=0;j<26;j++){
				if(a[j])t++,a[j]=false;
			}
			if(s<t)s=t;
		}
	}
	for(i=0,t=0;i<26;i++){
		if(a[i])t++;
	}
	if(s<t)s=t;
	cout<<s<<endl;
	return 0;
}