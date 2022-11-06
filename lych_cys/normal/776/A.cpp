#include<bits/stdc++.h>
using namespace std;

string a[2],b[2];
void doit(){
	
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++){
				if (a[j].compare(b[k])==0){
					a[j]=b[k^1]; return;
				}
			}
}
int main(){
	cin>>a[0]>>a[1];
	int i,n;scanf("%d",&n);cout<<a[0]<<' '<<a[1]<<endl;
	for (i=1; i<=n; i++){
		cin>>b[0]>>b[1];doit();
		cout<<a[0]<<' '<<a[1]<<endl;
	}
	return 0;
}