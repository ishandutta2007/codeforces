#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int n,m;
	int i,j,k;
	int s[2];
	string sa,sb;
	int a[1005],b[1005];
	int da[10],db[10];
	char ca;
	memset(da,0,sizeof(da));
	memset(db,0,sizeof(db));
	cin>>n;
	cin>>sa>>sb;
	for(i=0;i<n;i++){
		for(j=0,ca='0';j<10;j++,ca++){
			if(sa[i]==ca)a[i]=j,da[j]++;
			if(sb[i]==ca)b[i]=j,db[j]++;
		}
	}
	for(i=9,j=0,s[0]=0;i>=0;i--){
		j+=da[i];
		if(j>db[i]){
			s[0]+=j-db[i];
			j=0;
		}else{
			j-=db[i];
		}
	}
	
	for(i=9,j=0,s[1]=0;i>=0;i--){
		if(j<da[i]){
			s[1]+=j;
			j=0;
		}else{
			j-=da[i];
			s[1]+=da[i];
		}
		j+=db[i];
	}
	for(i=0;i<2;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}